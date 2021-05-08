/********************************************************************************
** Form generated from reading UI file 'Planewar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANEWAR_H
#define UI_PLANEWAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PLANEWARClass
{
public:

    void setupUi(QWidget *PLANEWARClass)
    {
        if (PLANEWARClass->objectName().isEmpty())
            PLANEWARClass->setObjectName(QString::fromUtf8("PLANEWARClass"));
        PLANEWARClass->resize(600, 400);

        retranslateUi(PLANEWARClass);

        QMetaObject::connectSlotsByName(PLANEWARClass);
    } // setupUi

    void retranslateUi(QWidget *PLANEWARClass)
    {
        PLANEWARClass->setWindowTitle(QCoreApplication::translate("PLANEWARClass", "PLANEWAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PLANEWARClass: public Ui_PLANEWARClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANEWAR_H
