/**
 * @file dialog_wb.h
 * @brief This file contains the declaration of the dialog_wb class, a QDialog subclass.
 * @author Jorge Mora (jorgeadan.mora@ucr.ac.cr)
 * @version 0.1
 * @date 2023-07-05
 */

#ifndef DIALOG_WB_H
#define DIALOG_WB_H

#include <QDialog>

namespace Ui {
class dialog_wb;
}

/**
 * @class dialog_wb
 * @brief A dialog box class.
 * 
 * This class represents a custom QDialog that contains a UI and related methods.
 */
class dialog_wb : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a dialog_wb object.
     * 
     * @param parent Optional parent widget.
     */
    explicit dialog_wb(QWidget *parent = nullptr);

    /**
     * @brief Returns the button's name.
     * 
     * @return QString The button's name.
     */
    QString getButtonName() const;

    /**
     * @brief Destroys the dialog_wb object, cleaning up its resources.
     */
    ~dialog_wb();

private:
    Ui::dialog_wb *ui; ///< Represents the user interface for the dialog.
};

#endif // DIALOG_WB_H
