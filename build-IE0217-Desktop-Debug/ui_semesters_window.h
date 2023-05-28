/********************************************************************************
** Form generated from reading UI file 'semesters_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEMESTERS_WINDOW_H
#define UI_SEMESTERS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_semesters_window
{
public:

    void setupUi(QWidget *semesters_window)
    {
        if (semesters_window->objectName().isEmpty())
            semesters_window->setObjectName(QString::fromUtf8("semesters_window"));
        semesters_window->resize(400, 300);

        retranslateUi(semesters_window);

        QMetaObject::connectSlotsByName(semesters_window);
    } // setupUi

    void retranslateUi(QWidget *semesters_window)
    {
        semesters_window->setWindowTitle(QApplication::translate("semesters_window", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class semesters_window: public Ui_semesters_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEMESTERS_WINDOW_H
