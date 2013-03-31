#include "qc_applicationwindow.h"

QC_ApplicationWindow::QC_ApplicationWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

QC_ApplicationWindow::~QC_ApplicationWindow()
{

}
