#pragma once
#ifndef AppViewer_H
#define AppViewer_H

//#include <list>
#include <QtWidgets/QMainWindow>
#include "ui_appviewer.h"
#include "AppModel.h"
#include "HealthCareUnit.h"

class AppViewer : public QMainWindow
{
	Q_OBJECT

public:
	AppViewer(QWidget *parent = 0);
	~AppViewer();

	//Methods handling line edits etc
	//Verification
	QString getLine(QLineEdit *qle);
	void tryLineEdit(QLineEdit *qle);
	bool lineIsNum(QString qstr);
	//Availability of line edits
	void enableEditingPanel(bool arg);
	void enableAddingStuff(bool arg);
	void enableSavingName(bool arg);
	//Enables only lineEdits for specific type of objects
	void enableEditingFields(HCUType type);

	//Information refreshing
	void refreshTextBrowser(HealthCareUnit &hcu);
	void refreshListWidget();
	void refreshImagePath();

	//Clearing browers and lineEdits
	void clearTextBrowserInfo();
	void clearEditingPanel();

	//Functions to modify model and list widget
	void getSelectedItemFromList();
	HCUType getItemType(HealthCareUnit &hcu);
	
	//Objects edition
	void updateModelList(QString newName);
	void updateSelection(HCUType type);			//changes model.hcu to the one selected from list
	void removeSelectedObjectFromModel();
	//Adding stuff to objects
	//General
	void addEquipmentToSelectedObject();
	void setImageInSelectedObject();
	//Specific
	void addPatientsToSelectedObject();
	void addWorkersToSelectedObject();
	void setPriceInSelectedBeauty();
	void addServiceToSelectedObject();
	//Objects update
	void updateEditedClinic();
	void updateEditedBeauty();
	void updateEditedNails();
	
	//Checks anything is in lineEdits
	bool updatePossible();

	//ListWidget edition
	void updateListAfterAddingObject(QString newName);
	void removeSelectedObjectFromListWidget();
	//Flags modification
	void setEditionFlags(bool arg);

//Slots
private slots:
	void on_pushButtonClose_clicked();
	//left panel buttons
	void on_pushButtonBrowse_clicked();
	void on_pushButtonAddStuff_clicked();
	void on_pushButtonSaveName_clicked();

	//right panel buttons
	void on_pushButtonAddClinic_clicked();
	void on_pushButtonAddNails_clicked();
	void on_pushButtonAddBeauty_clicked();
	void on_pushButtonDelete_clicked();
	//listwidget
	void on_listWidget_itemClicked();

private:
	Ui::AppViewerClass ui;
	AppModel model;

	bool editingC, editingBS, editingNAS;
	bool newObjectCreated;
};

#endif // AppViewer_H
