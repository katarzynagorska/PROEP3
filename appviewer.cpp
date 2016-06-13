#include "AppViewer.h"
#include <qmessagebox.h>
//#include "utilities.h"
#include "MyList.h"
#include "Clinic.h"
#include <iostream>

using namespace std;

AppViewer::AppViewer(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	//resetting all flags
	editingBS = false;
	editingNAS = false;
	editingC = false;

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


	//ui.gridLayoutEdit->setEnabled(arg);
}
//left panel buttons - essential to saving new object
//Ustawienie nazwy obiektu
void AppViewer::on_pushButtonSaveName_clicked(){

	//Verifying data, returning if not ok
	QString newName = getLine(ui.lineEditName);
	if (newName.isEmpty()) return;

	//Clinic case
	if (editingC){
		//When new Clinic is made
		//Adding new clinic to model
		model.getClinic().setName(newName.toStdString());
		model.addObject(model.getClinic());
		
		//Adding new clinic to listwidget
		new QListWidgetItem(QString::fromStdString(model.getClinic().getName()), ui.listWidget);

		ui.textBrowserMyDebug->setText("Rozmiar listy " + QString::fromStdString(to_string(model.list.size())));
		ui.textBrowserInfo->setText(QString::fromStdString(model.list.end()->infoToStr()));

		//Disabling edition
		enableEditingPanel(false);
		editingC = false;



		//else if (editingBS){
		//	model.getBeauty().setName(newName.toStdString());
		//}
		//else if (editingNAS){
		//	model.getNails().setName(newName.toStdString());
		//}
		
	}
	//else{
	//	QMessageBox::critical(this, "Error", "Nie edytujesz ¿adnego obiektu");
	//}
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

	//ui.textBrowserInfo->setText("Wybrano " + QString::fromStdString(to_string(ui.listWidget->currentRow())) + " pozycje na liscie\n"
	//	+ "Lista ma " + QString::fromStdString(to_string(model.list.size())) + " pozycji\n");

	QMessageBox::critical(this, "Error", QString::fromStdString(model.list.at(0)->infoToStr()));

	//ui.textBrowserMyDebug->setText(QString::fromStdString(model.getList().at(0)->infoToStr()));
	//QMessageBox::critical(this, "Error", "DUPA2");
	//for (int i = 0; i < model.list.size(); i++){
	//	ui.textBrowserMyDebug->setText(QString::fromStdString(model.list.at(ui.listWidget->currentRow())->infoToStr()));
	//	QMessageBox::critical(this, "Error", QString::fromStdString(model.list.at(ui.listWidget->currentRow())->infoToStr()));
	//}


	//cout << model.list.at(ui.listWidget->currentRow())->infoToStr() << endl;
	//	ui.textBrowserMyDebug->setText( "Dane obiektu z pozycji: " + QString::fromStdString(to_string(ui.listWidget->currentRow()))
	//		+ "\n" + QString::fromStdString(model.list.at(ui.listWidget->currentRow())->infoToStr()));

	//	ui.textBrowserMyDebug->setText(QString::fromStdString(model.list.at(ui.listWidget->currentRow())->infoToStr()));
	//	model.getHCU() = model.getObject(ui.listWidget->currentRow());
	//	ui.textBrowserMyDebug->setText("Rozmiar listy: "QString::fromStdString(model.getObject(ui.listWidget->currentRow()).infoToStr()));
}

//
//void AppViewer::on_pushButtonSave_clicked(){
//
//	ui.textBrowserInfo->setText("Wciœniêto Save");
//	
//	if (editingC)
//	{
//		try{
//			if (model.clinicIsReady())
//			{
//				Clinic newC = model.getClinic();
//				
//				model.addObject(newC);
//				ui.textBrowserMyDebug->setText("Rozmiar listy " + QString::fromStdString(to_string(model.list.size())));
//				ui.textBrowserInfo->setText(QString::fromStdString(model.list.end()->infoToStr()));
//
//				new QListWidgetItem(QString::fromStdString(newC.getName()), ui.listWidget);
//			}
//		}
//		catch (QString *strErrMsg)
//		{
//			QMessageBox::critical(this, "Error", *strErrMsg);
//			return;
//		}
//
//	}
//	else if (editingNAS)
//	{
//		//nailartsaloon stuff
//	}
//	else if (editingBS){
//		//beautystudio stuff
//	}
//	else
//	{
//		QMessageBox::critical(this, "Error", "Nie edytujesz zadnego obiektu");
//		return;
//	}
//}
//right panel buttons//Right panel buttons
void AppViewer::on_pushButtonAddClinic_clicked(){
	editingC = true;
	enableEditingPanel(true);
}
void AppViewer::on_pushButtonAddNails_clicked(){
	editingNAS = true;
	enableEditingPanel(true);
}
void AppViewer::on_pushButtonAddBeauty_clicked(){
	editingBS = true;
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