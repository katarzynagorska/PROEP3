#include "appviewer.h"
#include <qmessagebox.h>
#include "mylist.h"
#include "clinic.h"

using namespace std;

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
	ui.lineEditImage->setEnabled(arg);
	ui.lineEditEquipment->setEnabled(arg);
	ui.lineEditName->setEnabled(arg);
	ui.lineEditPatient->setEnabled(arg);
	ui.lineEditPrice->setEnabled(arg);
	ui.lineEditService->setEnabled(arg);
	ui.lineEditWorker->setEnabled(arg);

	ui.pushButtonAddStuff->setEnabled(arg);
	ui.pushButtonBrowse->setEnabled(arg);
	ui.pushButtonSaveName->setEnabled(arg);
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
	//When new object was created
	//Adding new hcu to listwidget
	if (newObjectCreated)
		new QListWidgetItem(QString::fromStdString(model.list.back()->getName()), ui.listWidget);
	else
	{
		;
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

//TODO okno ³adowania pliku;
//za³adowanie obrazu
void AppViewer::on_pushButtonBrowse_clicked(){

}

//Right panel - list widget representing myLIst of HCU*
void AppViewer::on_listWidget_currentItemChanged(){
	newObjectCreated = false;
	//Clinic case
	model.hcu = model.list.at(ui.listWidget->currentRow());
	string type = model.hcu->classType();
	if (type == "clinic")
	{
		editingC = true;
		model.clinic = (Clinic&)*model.list.at(ui.listWidget->currentRow());
		QMessageBox::critical(this, "Error", "CLINIC");
	}

	if (type == "nails")
	{
		editingNAS = true;
		model.nails = (NailArtSaloon&)*model.list.at(ui.listWidget->currentRow());
		QMessageBox::critical(this, "Error", "NAILS");
	}

	if (type == "beauty")
	{
		editingBS = true;
		model.beauty = (BeautyStudio&)*model.list.at(ui.listWidget->currentRow());
		QMessageBox::critical(this, "Error", "BEAUTY");
	}

}

//Right panel buttons
void AppViewer::on_pushButtonAddClinic_clicked(){
	editingC = true;
	newObjectCreated = true;
	enableEditingPanel(true);
}
void AppViewer::on_pushButtonAddNails_clicked(){
	editingNAS = true;
	newObjectCreated = true;
	enableEditingPanel(true);
}
void AppViewer::on_pushButtonAddBeauty_clicked(){
	editingBS = true;
	newObjectCreated = true;
	enableEditingPanel(true);
}
void AppViewer::on_pushButtonDelete_clicked(){
	ui.textBrowserInfo->setText("Wciœniêto Usuñ");

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