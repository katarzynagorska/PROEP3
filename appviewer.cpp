#include"demo.h"
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

	scene = new QGraphicsScene(this);
}

AppViewer::~AppViewer()
{
	//	this->destroy;
}

//left panel buttons - essential to saving new object
//Adding new HCU, setting up its name
void AppViewer::on_pushButtonSaveName_clicked(){
	
	QString name = getLine(ui.lineEditName);

	updateModelList(name);
	updateListAfterAddingObject(name);

	clearTextBrowserInfo();
	enableEditingPanel(false);
	clearEditingPanel();
	setEditionFlags(false);
}

//Left panel adding stuff to HCU's
//TODO finish that
void AppViewer::on_pushButtonAddStuff_clicked(){

	switch (getItemType(model.getHCU())){
	case CLINIC:
		updateEditedClinic();
		break;

	case BEAUTY:
		updateEditedBeauty();
		break;

	case NAILS:
		updateEditedNails();
		break;

	default:
		return;
	}

	clearEditingPanel();
	enableEditingPanel(false);
	refreshTextBrowser(model.getHCU());
	setEditionFlags(false);
}

//Getting image filepath
void AppViewer::on_pushButtonBrowse_clicked(){
	refreshImagePath();
	QString filepath = ui.lineEditImage->text();
	QImage img(filepath);
	displayImage(img);
}

//Right panel - list widget representing myLIst of HCU*
//void AppViewer::on_listWidget_currentItemChanged(){}
void AppViewer::on_listWidget_itemClicked(){	
	getSelectedItemFromList();	
	enableEditingFields(getItemType(model.getHCU()));
	updateSelection(getItemType(model.getHCU()));
	displayImage(model.getHCU().getImage());
}

//Right panel buttons
void AppViewer::on_pushButtonAddClinic_clicked(){
	clearEditingPanel();
	setEditionFlags(false);
	editingC = true;

	newObjectCreated = true;
	enableSavingName(true);
	enableAddingStuff(false);
}
void AppViewer::on_pushButtonAddNails_clicked(){
	clearEditingPanel();
	setEditionFlags(false);
	editingNAS = true;

	newObjectCreated = true;
	enableSavingName(true);
	enableAddingStuff(false);
}

void AppViewer::on_pushButtonAddBeauty_clicked(){
	clearEditingPanel();
	setEditionFlags(false);
	editingBS = true;

	newObjectCreated = true;
	enableSavingName(true);
	enableAddingStuff(false);
}
void AppViewer::on_pushButtonClose_clicked(){
	this->close();
}

void AppViewer::on_pushButtonDemo_clicked(){
	addDemo();
	refreshListWidget();
	ui.pushButtonDemo->setDisabled(true);
	setEditionFlags(false);
}

void AppViewer::on_pushButtonDelete_clicked(){
	removeSelectedObjectFromListWidget();
	removeSelectedObjectFromModel();
	clearTextBrowserInfo();
}

void AppViewer::removeSelectedObjectFromModel(){
	model.list.erase(selectedRow);
}

void AppViewer::removeSelectedObjectFromListWidget(){
	QListWidgetItem *toremove = new QListWidgetItem;
	toremove = ui.listWidget->takeItem(selectedRow);
	delete toremove;
}

void AppViewer::updateModelList(QString newName){
	//Verifying data, returning if not ok
	//QString newName = getLine(ui.lineEditName);
	if (newName.isEmpty()) return;

	//Adding new objects / editing existing
	if (!newObjectCreated){
		model.setObjectName(selectedRow, newName.toStdString());
	}
	else if (editingC){
		model.addNewObject(newName.toStdString(), CLINIC);
	}
	else if (editingBS){
		model.addNewObject(newName.toStdString(), BEAUTY);
	}
	else if (editingNAS){
		model.addNewObject(newName.toStdString(), NAILS);
	}
}

void AppViewer::updateListAfterAddingObject(QString newName){
	QString objectType;

	if (editingC){
		objectType = "Przychodnia";
	}
	else if (editingBS){
		objectType = "Salon pieknosci";
	}
	else if (editingNAS){
		objectType = "Studio paznokci";
	}


	//Refreshing ListWidget
	QListWidgetItem *item = new QListWidgetItem;
	QListWidgetItem *toremove = new QListWidgetItem;
	item->setText(objectType + " : " + newName);
	//Adding new hcu to listwidget
	//When new object was created
	if (newObjectCreated){
		if (!newName.isEmpty())
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
}

void AppViewer::addEquipmentToSelectedObject(){
	QString equipment = ui.lineEditEquipment->text();
	if (!equipment.isEmpty()){		
		model.getHCU().addEquipment(equipment.toStdString());
	}
}

void AppViewer::setImageInSelectedObject(){
	QString filepath = ui.lineEditImage->text();
	if (!filepath.isEmpty()){
		model.getHCU().setImage(filepath.toStdString());
	}
}

void AppViewer::displayImage(QImage img){
	scene->clear();
	QImage resized = img.scaled(ui.graphicsView->size() *= 0.85, Qt::KeepAspectRatio);
	scene->addPixmap(QPixmap::fromImage(resized));
	scene->setSceneRect(resized.rect());
	ui.graphicsView->setScene(scene);
}

void AppViewer::addPatientsToSelectedObject(){
	QString patient = ui.lineEditPatient->text();
	if (!patient.isEmpty()) {
		((Clinic*)&model.getHCU())->addPatient(patient.toStdString());
	}
}

void AppViewer::addWorkersToSelectedObject(){
	QString worker = ui.lineEditWorker->text();
	if (!worker.isEmpty())	{
				((BeautyStudio*)&model.getHCU())->addBeautician(worker.toStdString());
			}
}

void AppViewer::updateEditedClinic(){

	if (updatePossible()){
		addEquipmentToSelectedObject();
		setImageInSelectedObject();
		addPatientsToSelectedObject();
	}

}

void AppViewer::updateEditedBeauty(){
	if (updatePossible()){
		addEquipmentToSelectedObject();
		setImageInSelectedObject();
		addWorkersToSelectedObject();
		setPriceInSelectedBeauty();
	}
}

void AppViewer::updateEditedNails(){
	if (updatePossible()){
		addEquipmentToSelectedObject();
		setImageInSelectedObject();
		addWorkersToSelectedObject();
		addServiceToSelectedObject();
	}
}

void AppViewer::setPriceInSelectedBeauty(){
	QString price = ui.lineEditPrice->text();
	if (!price.isEmpty()){
		if (lineIsNum(price)){
			((BeautyStudio*)&model.getHCU())->setPrice(price.toInt());
		}
		else{
			QMessageBox::critical(this, "Error", "Wprowadz dane liczbowe w polu ceny");
			return;
		}
	}
}

void AppViewer::addServiceToSelectedObject(){
	QString service = ui.lineEditService->text();
	QString price = ui.lineEditPrice->text();
	int price_num;

	if (price.isEmpty() && service.isEmpty())
		return;

	else if ((price.isEmpty()) ^ (service.isEmpty())){
		QMessageBox::critical(this, "Error", "Wprowadz cene i nazwe uslugi");
		return;
	}

	else if (lineIsNum(price)){
		price_num = price.toInt();
		((NailArtSaloon*)&model.getHCU())->addService(service.toStdString(), price_num);
	}
	else{
		QMessageBox::critical(this, "Error", "Wprowadz dane liczbowe w polu ceny");
		return;
	}	
}

bool AppViewer::updatePossible(){
	QString equipment = ui.lineEditEquipment->text();
	QString patient = ui.lineEditPatient->text();
	QString filepath = ui.lineEditImage->text();
	QString service = ui.lineEditService->text();
	QString price = ui.lineEditPrice->text();
	QString worker = ui.lineEditWorker->text();
	
	if (equipment.isEmpty() && patient.isEmpty() && filepath.isEmpty() && service.isEmpty() && price.isEmpty() && worker.isEmpty())
	{
		QMessageBox::critical(this, "Error", "Wprowadz dane");
		return false;
	}
	else
		return true;
}

void AppViewer::refreshImagePath(){
	QString imagePath = QFileDialog::getOpenFileName(this, "Open File", "", "JPEG (*.jpg *.jpeg);;PNG (*.png)");
	ui.lineEditImage->setText(imagePath);
}

void AppViewer::refreshTextBrowser(HealthCareUnit &hcu){
	ui.textBrowserInfo->setText(QString::fromStdString(hcu.infoToStr()));
}

void AppViewer::getSelectedItemFromList(){
	newObjectCreated = false;
	enableEditingPanel(true);

	selectedRow = ui.listWidget->currentRow();

	model.hcu = model.list.at(ui.listWidget->currentRow());
	//model.getHCU() = *model.list.at(ui.listWidget->currentRow());
	//model.setHCU(*model.list.at(ui.listWidget->currentRow()));
	refreshTextBrowser(model.getHCU());
}

HCUType AppViewer::getItemType(HealthCareUnit &hcu){
	HCUType _type;

	string type = hcu.classType();
	if (type == "clinic") _type = CLINIC;
	if (type == "nails") _type = NAILS;
	if (type == "beauty") _type = BEAUTY;

	return _type;
}

void AppViewer::enableEditingFields(HCUType type)
{
	switch (type){
	case CLINIC:
		ui.lineEditPrice->setDisabled(true);
		ui.lineEditService->setDisabled(true);
		ui.lineEditWorker->setDisabled(true);
		break;

	case BEAUTY:
		ui.lineEditPatient->setDisabled(true);
		ui.lineEditService->setDisabled(true);
		break;

	case NAILS:
		ui.lineEditPatient->setDisabled(true);
		break;

	default:
		return;
	}
}

void AppViewer::updateSelection(HCUType type){
	switch (type){
	case CLINIC:
		editingC = true;
		model.getClinic() = (Clinic&)*model.list.at(ui.listWidget->currentRow());
		break;

	case BEAUTY:
		editingBS = true;
		model.getBeauty() = (BeautyStudio&)*model.list.at(ui.listWidget->currentRow());
		break;

	case NAILS:
		editingNAS = true;
		model.getNails() = (NailArtSaloon&)*model.list.at(ui.listWidget->currentRow());
		break;

	default:
		return;
	}
}

//Not very effective
void AppViewer::refreshListWidget(){
	string type;
	QString prfx;
	ui.listWidget->clear();
	for (int i = 0; i < model.list.size(); i++)
	{
		type = model.list.at(i)->classType();
		if (type == "clinic") prfx = "Przychodnia : ";
		if (type == "beauty") prfx = "Salon pieknosci : ";
		if (type == "nails") prfx = "Studio paznokci : ";
		
		ui.listWidget->addItem(prfx + QString::fromStdString(model.list.at(i)->getName()));
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
	scene->clear();
	//ui.graphicsView->setScene(scene);
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


//Enabling all fields
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

//EditionFlagsSetUp
void AppViewer::setEditionFlags(bool arg){
	editingC = arg;
	editingNAS = arg;
	editingBS = arg;
}

void AppViewer::addDemo(){
	setUpDemos();
	model.addObject(szaserow);
	model.addObject(banacha);
	model.addObject(woloska);
	model.addObject(pazur);
	model.addObject(manicureexpress);	
	model.addObject(piekna);
}