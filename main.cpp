#include "appviewer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AppViewer w;
	w.setWindowTitle("Katarzyna Gorska");
	w.setFixedSize(880, 660);
	w.show();
	return a.exec();
}
