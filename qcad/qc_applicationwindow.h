#ifndef QCAD_H
#define QCAD_H

#include <QtGui/QMainWindow>
#include "ui_qcad.h"

class QC_ApplicationWindow : public QMainWindow,
	QG_MainWindowInterface
{
	Q_OBJECT

public:
	QC_ApplicationWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QC_ApplicationWindow();

private:
	Ui::qcadClass ui;
};

#endif // QCAD_H
