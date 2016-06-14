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

	//Methods handling line edits stuff
	QString getLine(QLineEdit *qle);
	void tryLineEdit(QLineEdit *qle);
	void lineIsNum(QString qstr);

	void enableEditingPanel(bool arg);
	void enableAddingStuff(bool arg);
	void enableSavingName(bool arg);
	void dupa();
	void refreshTextBrowser(HealthCareUnit &hcu);
	void refreshListWidget();

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
	void on_listWidget_currentItemChanged();

private:
	Ui::AppViewerClass ui;
	AppModel model;

	bool editingC, editingBS, editingNAS;
	bool newObjectCreated;
};

#endif // AppViewer_H
