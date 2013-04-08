#include "qc_applicationwindow.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QC_ApplicationWindow w;
	w.show();
	return a.exec();
}
