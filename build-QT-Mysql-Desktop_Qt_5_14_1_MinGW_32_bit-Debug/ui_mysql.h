/********************************************************************************
** Form generated from reading UI file 'mysql.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSQL_H
#define UI_MYSQL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mysql
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mysql)
    {
        if (Mysql->objectName().isEmpty())
            Mysql->setObjectName(QString::fromUtf8("Mysql"));
        Mysql->resize(800, 600);
        centralwidget = new QWidget(Mysql);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Mysql->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mysql);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Mysql->setMenuBar(menubar);
        statusbar = new QStatusBar(Mysql);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Mysql->setStatusBar(statusbar);

        retranslateUi(Mysql);

        QMetaObject::connectSlotsByName(Mysql);
    } // setupUi

    void retranslateUi(QMainWindow *Mysql)
    {
        Mysql->setWindowTitle(QCoreApplication::translate("Mysql", "Mysql", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mysql: public Ui_Mysql {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSQL_H
