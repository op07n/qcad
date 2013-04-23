/********************************************************************************
** Form generated from reading UI file 'qcad.ui'
**
** Created: Tue Apr 23 09:28:00 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCAD_H
#define UI_QCAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qcadClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qcadClass)
    {
        if (qcadClass->objectName().isEmpty())
            qcadClass->setObjectName(QString::fromUtf8("qcadClass"));
        qcadClass->resize(600, 400);
        menuBar = new QMenuBar(qcadClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        qcadClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qcadClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        qcadClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(qcadClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qcadClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qcadClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qcadClass->setStatusBar(statusBar);

        retranslateUi(qcadClass);

        QMetaObject::connectSlotsByName(qcadClass);
    } // setupUi

    void retranslateUi(QMainWindow *qcadClass)
    {
        qcadClass->setWindowTitle(QApplication::translate("qcadClass", "qcad", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qcadClass: public Ui_qcadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCAD_H
