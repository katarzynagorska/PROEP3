#include "appviewer.h"
#include <qmessagebox.h>
#include "mylist.h"
#include "clinic.h"

using namespace std;

int selectedRow;

AppViewer::AppViewer(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	//resetting all flags
	editingBS = false;
	editingNAS = false;
	editingC = false;
	newObjectCreated = false;

	enableEditingPanel(false);

}

AppViewer::~AppViewer()
{
	//	this->destroy;
}


void AppViewer::on_pushButtonClose_clicked(){
	this->close();
}

void AppViewer::enableEditingPanel(bool arg){
	enableAddingStuff(arg);
	enableSavingName(arg);
}

void AppViewer::enableSavingName(bool arg){
	ui.lineEditName->setEnabled(arg);
	ui.pushButtonSaveName->setEnabled(arg);
}

void AppViewer::enableAddingStuff(bool arg){
	ui.lineEditImage->setEnabled(arg);
	ui.lineEditEquipment->setEnabled(arg);
	
	ui.lineEditPatient->setEnabled(arg);
	ui.lineEditPrice->setEnabled(arg);
	ui.lineEditService->setEnabled(arg);
	ui.lineEditWorker->setEnabled(arg);

	ui.pushButtonAddStuff->setEnabled(arg);
	ui.pushButtonBrowse->setEnabled(arg);
}

//left panel buttons - essential to saving new object
//Adding new HCU, setting up its name
void AppViewer::on_pushButtonSaveName_clicked(){

	//Verifying data, returning if not ok
	QString newName = getLine(ui.lineEditName);
	if (newName.isEmpty()) return;

	if (editingC){
		//Setting up name
		model.getClinic().setName(newName.toStdString());
		//Adding object to list only if it is newly created
		if (newObjectCreated){		
			model.addObject(model.getClinic());
		}

	}
	else if (editingBS){
		//Setting up name
		model.getBeauty().setName(newName.toStdString());
		//Adding object to list only if it is newly created
		if (newObjectCreated){		
			model.addObject(model.getBeauty());
		}
	}

	else if (editingNAS){
		//Setting up name
		model.getNails().setName(newName.toStdString());
		//Adding object to list only if it is newly created
		if (newObjectCreated){		
			model.addObject(model.getNails());
		}		
	}
	
	
	QListWidgetItem *item = new QListWidgetItem; //, ui.listWidget);
	QListWidgetItem *toremove = new QListWidgetItem;
	item->setText(QString::fromStdString(model.list.back()->getName()));
	
	//Adding new hcu to listwidget
	//When new object was created
	if (newObjectCreated){
		ui.listWidget->addItem(item);
	}
	else
	{
		//Inserting edited name to list
		ui.listWidget->insertItem(selectedRow, item);
		//Deleting preedited item from list
		toremove = ui.listWidget->takeItem(selectedRow+1);
		delete toremove;
	}


	//Disabling edition
	enableEditingPanel(false);
	editingC = false;
	editingNAS = false;
	editingBS = false;
}

//Left panel adding stuff to HCU's
void AppViewer::on_pushButtonAddStuff_clicked(){

}

//TODO okno �adowania pliku;
//za�adowanie obrazu
void AppViewer::on_pushButtonBrowse_clicked(){

}

//Right panel - list widget representing myLIst of HCU*
void AppViewer::on_listWidget_currentItemChanged(){
	newObjectCreated = false;
	enableEditingPanel(true);

	selectedRow = ui.listWidget->currentRow();	
	
	model.hcu = model.list.at(ui.listWidget->currentRow());
	ui.textBrowserInfo->setText(QString::fromStdString(model.hcu->infoToStr()));

	string type = model.hcu->classType();
	if (type == "clinic")
	{
		editingC = true;
		model.clinic = (Clinic&)*model.list.at(ui.listWidget->currentRow());
	}

	if (type == "nails")
	{
		editingNAS = true;
		model.nails = (NailArtSaloon&)*model.list.at(ui.listWidget->currentRow());
	}

	if (type == "beauty")
	{
		editingBS = true;
		model.beauty = (BeautyStudio&)*model.list.at(ui.listWidget->currentRow());
	}
}

//Right panel buttons
void AppViewer::on_pushButtonAddClinic_clicked(){
	editingC = true;
	newObjectCreated = true;
	enableSavingName(true);
}
void AppViewer::on_pushButtonAddNails_clicked(){
	editingNAS = true;
	newObjectCreated = true;
	enableSavingName(true);
}
void AppViewer::on_pushButtonAddBeauty_clicked(){
	editingBS = true;
	newObjectCreated = true;
	enableSavingName(true);
}
void AppViewer::on_pushButtonDelete_clicked(){
	ui.textBrowserInfo->setText("Wci�ni�to Usu�");

}





//Error MssgBoxes and stuff
void AppViewer::tryLineEdit(QLineEdit *qle){
	if (qle->text().isEmpty())
		throw new QString("Wprowadz poprawna wartosc " + qle->objectName());
}

void AppViewer::lineIsNum(QString qstr){
	bool ok;
	int num = qstr.toInt(&ok, 10);
	if (!ok)
		throw new QString("Wprowadz poprawna wartosc liczbowa!");
}

QString AppViewer::getLine(QLineEdit *qle){
	try{
		if (qle == ui.lineEditPrice)
			lineIsNum(qle->text());
		else
			tryLineEdit(qle);
	}
	catch (QString *strErrMsg)
	{
		QMessageBox::critical(this, "Error", *strErrMsg);
		return "";
	}

	QString txt = qle->text();
	qle->setText("");
	return txt;
}