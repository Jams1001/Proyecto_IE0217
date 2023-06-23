/********************************************************************************
** Form generated from reading UI file 'dialog_wb.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_WB_H
#define UI_DIALOG_WB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_dialog_wb
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *dialog_wb)
    {
        if (dialog_wb->objectName().isEmpty())
            dialog_wb->setObjectName(QString::fromUtf8("dialog_wb"));
        dialog_wb->resize(400, 300);
        buttonBox = new QDialogButtonBox(dialog_wb);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 160, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(dialog_wb);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 100, 291, 41));

        retranslateUi(dialog_wb);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog_wb, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog_wb, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_wb);
    } // setupUi

    void retranslateUi(QDialog *dialog_wb)
    {
        dialog_wb->setWindowTitle(QApplication::translate("dialog_wb", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_wb: public Ui_dialog_wb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_WB_H
