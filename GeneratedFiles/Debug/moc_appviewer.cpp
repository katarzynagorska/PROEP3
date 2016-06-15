/****************************************************************************
** Meta object code from reading C++ file 'appviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../appviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AppViewer_t {
    QByteArrayData data[11];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppViewer_t qt_meta_stringdata_AppViewer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AppViewer"
QT_MOC_LITERAL(1, 10, 26), // "on_pushButtonClose_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 27), // "on_pushButtonBrowse_clicked"
QT_MOC_LITERAL(4, 66, 29), // "on_pushButtonAddStuff_clicked"
QT_MOC_LITERAL(5, 96, 29), // "on_pushButtonSaveName_clicked"
QT_MOC_LITERAL(6, 126, 30), // "on_pushButtonAddClinic_clicked"
QT_MOC_LITERAL(7, 157, 29), // "on_pushButtonAddNails_clicked"
QT_MOC_LITERAL(8, 187, 30), // "on_pushButtonAddBeauty_clicked"
QT_MOC_LITERAL(9, 218, 27), // "on_pushButtonDelete_clicked"
QT_MOC_LITERAL(10, 246, 25) // "on_listWidget_itemClicked"

    },
    "AppViewer\0on_pushButtonClose_clicked\0"
    "\0on_pushButtonBrowse_clicked\0"
    "on_pushButtonAddStuff_clicked\0"
    "on_pushButtonSaveName_clicked\0"
    "on_pushButtonAddClinic_clicked\0"
    "on_pushButtonAddNails_clicked\0"
    "on_pushButtonAddBeauty_clicked\0"
    "on_pushButtonDelete_clicked\0"
    "on_listWidget_itemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AppViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppViewer *_t = static_cast<AppViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonClose_clicked(); break;
        case 1: _t->on_pushButtonBrowse_clicked(); break;
        case 2: _t->on_pushButtonAddStuff_clicked(); break;
        case 3: _t->on_pushButtonSaveName_clicked(); break;
        case 4: _t->on_pushButtonAddClinic_clicked(); break;
        case 5: _t->on_pushButtonAddNails_clicked(); break;
        case 6: _t->on_pushButtonAddBeauty_clicked(); break;
        case 7: _t->on_pushButtonDelete_clicked(); break;
        case 8: _t->on_listWidget_itemClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AppViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AppViewer.data,
      qt_meta_data_AppViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppViewer.stringdata0))
        return static_cast<void*>(const_cast< AppViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AppViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
