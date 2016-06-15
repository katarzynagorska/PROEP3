#include "appviewer.h"
#include <qmessagebox.h>
#include "mylist.h"
#include "clinic.h"
#include<qfiledialog.h>

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
	ui.lineEditImage->setDisabled(true);


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

		if (newObjectCreated){
			model.addNewObject(newName.toStdString(), CLINIC);
		}
		else {
			model.setObjectName(selectedRow, newName.toStdString());
		}

	}
	else if (editingBS){
		if (newObjectCreated){
			model.addNewObject(newName.toStdString(), BEAUTY);
		}
		else {
			model.setObjectName(selectedRow, newName.toStdString());
		}
	}

	else if (editingNAS){
		if (newObjectCreated){
			model.addNewObject(newName.toStdString(), NAILS);
		}
		else {
			model.setObjectName(selectedRow, newName.toStdString());
		}
	}

	//Refreshing ListWidget
	QListWidgetItem *item = new QListWidgetItem; 
	QListWidgetItem *toremove = new QListWidgetItem;
	item->setText(newName);
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
		toremove = ui.listWidget->takeItem(selectedRow + 1);
		delete toremove;
	}

	
	//Disabling edition, clearing textbrowser
	clearTextBrowserInfo();
	enableEditingPanel(false);
	editingC = false;
	editingNAS = false;
	editingBS = false;
}

//Left panel adding stuff to HCU's
//TODO finish that
void AppViewer::on_pushButtonAddStuff_clicked(){
	string type = model.hcu->classType();

	QString equipment = ui.lineEditEquipment->text();
	QString patient = ui.lineEditPatient->text();
	QString filepath = ui.lineEditImage->text();
	QString service = ui.lineEditService->text();
	QString price = ui.lineEditPrice->text();
	QString worker = ui.lineEditWorker->text();

	//General settings
	if (equipment.isEmpty() && patient.isEmpty() && filepath.isEmpty() && service.isEmpty() && price.isEmpty() && worker.isEmpty())
	{
		QMessageBox::critical(this, "Error", "Wprowadz dane");
		return;
	}
	
	if (!equipment.isEmpty())
	{
		model.getHCU().addEquipment(equipment.toStdString());
	}

	if (!filepath.isEmpty())
	{
		model.getHCU().setImage(filepath.toStdString());
	}

	//Specific settings depending on object type
	if (type == "clinic")
	{
		if (!patient.isEmpty())
		{
			((Clinic*)&model.getHCU())->addPatient(patient.toStdString());
		}

	}
	else if (type == "beauty")
	{
		if (!worker.isEmpty())
		{
			((BeautyStudio*)&model.getHCU())->addBeautician(worker.toStdString());
		}
		if (!price.isEmpty())
		{
			if (lineIsNum(price))
			{
				((BeautyStudio*)&model.getHCU())->setPrice(price.toInt());
			}
			else
			{
				QMessageBox::critical(this, "Error", "Wprowadz dane liczbowe w polu ceny");
				return;
			}

		}
	}
	else if (type == "nails")
	{
		model.getNails() = (NailArtSaloon&)model.getHCU();

	}



	clearEditingPanel();
	enableEditingPanel(false);
	ui.textBrowserInfo->setText(QString::fromStdString(model.getHCU().infoToStr()));
}

//Getting image filepath
void AppViewer::on_pushButtonBrowse_clicked(){
	QString imagePath = QFileDialog::getOpenFileName(this, "Open File", "", "JPEG (*.jpg *.jpeg);;PNG (*.png)");
	ui.lineEditImage->setText(imagePath);
}

//Right panel - list widget representing myLIst of HCU*
//void AppViewer::on_listWidget_currentItemChanged(){}
void AppViewer::on_listWidget_itemClicked(){
	
	newObjectCreated = false;
	enableEditingPanel(true);

	selectedRow = ui.listWidget->currentRow();	
	
	model.hcu = model.list.at(ui.listWidget->currentRow());
	ui.textBrowserInfo->setText(QString::fromStdString(model.hcu->infoToStr()));

	string type = model.hcu->classType();

	//Disabling different fields when editing different objects
	if (type == "clinic")
	{
		editingC = true;
		model.getClinic() = (Clinic&)*model.list.at(ui.listWidget->currentRow());
		ui.lineEditPrice->setDisabled(true);
		ui.lineEditService->setDisabled(true);
		ui.lineEditWorker->setDisabled(true);
	}

	if (type == "nails")
	{
		editingNAS = true;
		model.getNails() = (NailArtSaloon&)*model.list.at(ui.listWidget->currentRow());
		ui.lineEditPatient->setDisabled(true);
	}

	if (type == "beauty")
	{
		editingBS = true;
		model.getBeauty() = (BeautyStudio&)*model.list.at(ui.listWidget->currentRow());
		ui.lineEditPatient->setDisabled(true);
		ui.lineEditService->setDisabled(true);
	}
}

//Right panel buttons
void AppViewer::on_pushButtonAddClinic_clicked(){
	editingC = true;
	newObjectCreated = true;
	enableSavingName(true);
	enableAddingStuff(false);
}
void AppViewer::on_pushButtonAddNails_clicked(){
	editingNAS = true;
	newObjectCreated = true;
	enableSavingName(true);
	enableAddingStuff(false);
}
void AppViewer::on_pushButtonAddBeauty_clicked(){
	editingBS = true;
	newObjectCreated = true;
	enableSavingName(true);
	enableAddingStuff(false);
}
void AppViewer::on_pushButtonDelete_clicked(){
	ui.textBrowserInfo->setText("Wci�ni�to Usu�");

}
//Not very effective
void AppViewer::refreshListWidget(){
	ui.listWidget->clear();
	for (int i = 0; i < model.list.size(); i++)
	{
		ui.listWidget->addItem(QString::fromStdString(model.list.at(i)->getName()));
	}
}

void AppViewer::clearTextBrowserInfo(){
	ui.textBrowserInfo->setText("");
}

void AppViewer::clearEditingPanel(){
	ui.lineEditEquipment->setText("");
	ui.lineEditPatient->setText("");
	ui.lineEditPrice->setText("");
	ui.lineEditService->setText("");
	ui.lineEditWorker->setText("");
	ui.lineEditImage->setText("");
	ui.lineEditName->setText("");
}

//Error MssgBoxes and stuff
void AppViewer::tryLineEdit(QLineEdit *qle){
	if (qle->text().isEmpty())
		throw new QString("Wprowadz poprawna wartosc " + qle->objectName());
}

bool AppViewer::lineIsNum(QString qstr){
	bool ok;
	int num = qstr.toInt(&ok, 10);
	return ok;
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