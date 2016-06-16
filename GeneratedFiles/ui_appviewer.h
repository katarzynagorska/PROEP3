/********************************************************************************
** Form generated from reading UI file 'appviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPVIEWER_H
#define UI_APPVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppViewerClass
{
public:
    QGraphicsView *graphicsView;
    QListWidget *listWidget;
    QTextBrowser *textBrowserInfo;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayoutEdit;
    QLineEdit *lineEditName;
    QLabel *labelChangeName;
    QLineEdit *lineEditImage;
    QLabel *labelAddImage;
    QLabel *labelAddService;
    QLabel *labelSetPrice;
    QLabel *labelAddWorker;
    QLabel *labelAddPatient;
    QLabel *labelAddEquipment;
    QPushButton *pushButtonBrowse;
    QPushButton *pushButtonSaveName;
    QLineEdit *lineEditEquipment;
    QLineEdit *lineEditPatient;
    QLineEdit *lineEditWorker;
    QLineEdit *lineEditPrice;
    QLineEdit *lineEditService;
    QPushButton *pushButtonAddStuff;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *pushButtonAddClinic;
    QPushButton *pushButtonAddNails;
    QPushButton *pushButtonAddBeauty;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonClose;
    QPushButton *pushButtonDemo;

    void setupUi(QWidget *AppViewerClass)
    {
        if (AppViewerClass->objectName().isEmpty())
            AppViewerClass->setObjectName(QStringLiteral("AppViewerClass"));
        AppViewerClass->resize(869, 670);
        graphicsView = new QGraphicsView(AppViewerClass);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 351, 201));
        listWidget = new QListWidget(AppViewerClass);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(370, 10, 491, 501));
        textBrowserInfo = new QTextBrowser(AppViewerClass);
        textBrowserInfo->setObjectName(QStringLiteral("textBrowserInfo"));
        textBrowserInfo->setGeometry(QRect(10, 220, 351, 151));
        gridLayoutWidget_2 = new QWidget(AppViewerClass);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 380, 351, 265));
        gridLayoutEdit = new QGridLayout(gridLayoutWidget_2);
        gridLayoutEdit->setSpacing(6);
        gridLayoutEdit->setContentsMargins(11, 11, 11, 11);
        gridLayoutEdit->setObjectName(QStringLiteral("gridLayoutEdit"));
        gridLayoutEdit->setContentsMargins(0, 0, 0, 0);
        lineEditName = new QLineEdit(gridLayoutWidget_2);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        gridLayoutEdit->addWidget(lineEditName, 1, 1, 1, 1);

        labelChangeName = new QLabel(gridLayoutWidget_2);
        labelChangeName->setObjectName(QStringLiteral("labelChangeName"));

        gridLayoutEdit->addWidget(labelChangeName, 1, 0, 1, 1);

        lineEditImage = new QLineEdit(gridLayoutWidget_2);
        lineEditImage->setObjectName(QStringLiteral("lineEditImage"));

        gridLayoutEdit->addWidget(lineEditImage, 2, 1, 1, 1);

        labelAddImage = new QLabel(gridLayoutWidget_2);
        labelAddImage->setObjectName(QStringLiteral("labelAddImage"));

        gridLayoutEdit->addWidget(labelAddImage, 2, 0, 1, 1);

        labelAddService = new QLabel(gridLayoutWidget_2);
        labelAddService->setObjectName(QStringLiteral("labelAddService"));

        gridLayoutEdit->addWidget(labelAddService, 8, 0, 1, 1);

        labelSetPrice = new QLabel(gridLayoutWidget_2);
        labelSetPrice->setObjectName(QStringLiteral("labelSetPrice"));

        gridLayoutEdit->addWidget(labelSetPrice, 9, 0, 1, 1);

        labelAddWorker = new QLabel(gridLayoutWidget_2);
        labelAddWorker->setObjectName(QStringLiteral("labelAddWorker"));

        gridLayoutEdit->addWidget(labelAddWorker, 7, 0, 1, 1);

        labelAddPatient = new QLabel(gridLayoutWidget_2);
        labelAddPatient->setObjectName(QStringLiteral("labelAddPatient"));

        gridLayoutEdit->addWidget(labelAddPatient, 5, 0, 1, 1);

        labelAddEquipment = new QLabel(gridLayoutWidget_2);
        labelAddEquipment->setObjectName(QStringLiteral("labelAddEquipment"));

        gridLayoutEdit->addWidget(labelAddEquipment, 6, 0, 1, 1);

        pushButtonBrowse = new QPushButton(gridLayoutWidget_2);
        pushButtonBrowse->setObjectName(QStringLiteral("pushButtonBrowse"));

        gridLayoutEdit->addWidget(pushButtonBrowse, 2, 2, 1, 1);

        pushButtonSaveName = new QPushButton(gridLayoutWidget_2);
        pushButtonSaveName->setObjectName(QStringLiteral("pushButtonSaveName"));

        gridLayoutEdit->addWidget(pushButtonSaveName, 1, 2, 1, 1);

        lineEditEquipment = new QLineEdit(gridLayoutWidget_2);
        lineEditEquipment->setObjectName(QStringLiteral("lineEditEquipment"));

        gridLayoutEdit->addWidget(lineEditEquipment, 6, 1, 1, 2);

        lineEditPatient = new QLineEdit(gridLayoutWidget_2);
        lineEditPatient->setObjectName(QStringLiteral("lineEditPatient"));

        gridLayoutEdit->addWidget(lineEditPatient, 5, 1, 1, 2);

        lineEditWorker = new QLineEdit(gridLayoutWidget_2);
        lineEditWorker->setObjectName(QStringLiteral("lineEditWorker"));

        gridLayoutEdit->addWidget(lineEditWorker, 7, 1, 1, 2);

        lineEditPrice = new QLineEdit(gridLayoutWidget_2);
        lineEditPrice->setObjectName(QStringLiteral("lineEditPrice"));

        gridLayoutEdit->addWidget(lineEditPrice, 9, 1, 1, 2);

        lineEditService = new QLineEdit(gridLayoutWidget_2);
        lineEditService->setObjectName(QStringLiteral("lineEditService"));

        gridLayoutEdit->addWidget(lineEditService, 8, 1, 1, 2);

        pushButtonAddStuff = new QPushButton(gridLayoutWidget_2);
        pushButtonAddStuff->setObjectName(QStringLiteral("pushButtonAddStuff"));

        gridLayoutEdit->addWidget(pushButtonAddStuff, 10, 0, 1, 3);

        horizontalLayoutWidget = new QWidget(AppViewerClass);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(370, 520, 493, 73));
        horizontalLayoutButtons = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayoutButtons->setSpacing(6);
        horizontalLayoutButtons->setContentsMargins(11, 11, 11, 11);
        horizontalLayoutButtons->setObjectName(QStringLiteral("horizontalLayoutButtons"));
        horizontalLayoutButtons->setContentsMargins(0, 0, 0, 0);
        pushButtonAddClinic = new QPushButton(horizontalLayoutWidget);
        pushButtonAddClinic->setObjectName(QStringLiteral("pushButtonAddClinic"));

        horizontalLayoutButtons->addWidget(pushButtonAddClinic);

        pushButtonAddNails = new QPushButton(horizontalLayoutWidget);
        pushButtonAddNails->setObjectName(QStringLiteral("pushButtonAddNails"));

        horizontalLayoutButtons->addWidget(pushButtonAddNails);

        pushButtonAddBeauty = new QPushButton(horizontalLayoutWidget);
        pushButtonAddBeauty->setObjectName(QStringLiteral("pushButtonAddBeauty"));

        horizontalLayoutButtons->addWidget(pushButtonAddBeauty);

        pushButtonDelete = new QPushButton(horizontalLayoutWidget);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));

        horizontalLayoutButtons->addWidget(pushButtonDelete);

        pushButtonClose = new QPushButton(AppViewerClass);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(740, 600, 121, 41));
        pushButtonDemo = new QPushButton(AppViewerClass);
        pushButtonDemo->setObjectName(QStringLiteral("pushButtonDemo"));
        pushButtonDemo->setGeometry(QRect(370, 600, 361, 41));

        retranslateUi(AppViewerClass);

        QMetaObject::connectSlotsByName(AppViewerClass);
    } // setupUi

    void retranslateUi(QWidget *AppViewerClass)
    {
        AppViewerClass->setWindowTitle(QApplication::translate("AppViewerClass", "AppViewer", 0));
        textBrowserInfo->setHtml(QApplication::translate("AppViewerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        labelChangeName->setText(QApplication::translate("AppViewerClass", "Zmie\305\204 nazw\304\231:", 0));
        labelAddImage->setText(QApplication::translate("AppViewerClass", "Dodaj obraz:", 0));
        labelAddService->setText(QApplication::translate("AppViewerClass", "Dodaj us\305\202ug\304\231:", 0));
        labelSetPrice->setText(QApplication::translate("AppViewerClass", "Ustaw cen\304\231:", 0));
        labelAddWorker->setText(QApplication::translate("AppViewerClass", "Dodaj pracownika:", 0));
        labelAddPatient->setText(QApplication::translate("AppViewerClass", "Dodaj pacjenta:", 0));
        labelAddEquipment->setText(QApplication::translate("AppViewerClass", "Dodaj wyposa\305\274enie:", 0));
        pushButtonBrowse->setText(QApplication::translate("AppViewerClass", "Przegl\304\205daj", 0));
        pushButtonSaveName->setText(QApplication::translate("AppViewerClass", "Zapisz", 0));
        pushButtonAddStuff->setText(QApplication::translate("AppViewerClass", "Dodaj", 0));
        pushButtonAddClinic->setText(QApplication::translate("AppViewerClass", "Dodaj Przychodni\304\231", 0));
        pushButtonAddNails->setText(QApplication::translate("AppViewerClass", "Dodaj Studio Paznokci", 0));
        pushButtonAddBeauty->setText(QApplication::translate("AppViewerClass", "Dodaj Salon Pi\304\231kno\305\233ci", 0));
        pushButtonDelete->setText(QApplication::translate("AppViewerClass", "Usu\305\204", 0));
        pushButtonClose->setText(QApplication::translate("AppViewerClass", "Zako\305\204cz", 0));
        pushButtonDemo->setText(QApplication::translate("AppViewerClass", "Demo", 0));
    } // retranslateUi

};

namespace Ui {
    class AppViewerClass: public Ui_AppViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPVIEWER_H
