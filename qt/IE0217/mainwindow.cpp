#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog_wb.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isSelectionMode(false)
{
    ui->setupUi(this);
    layout1 = new QVBoxLayout;
    ui->scrollAreaWidgetContents->setLayout(layout1);
    QVBoxLayout *layout2 = new QVBoxLayout;
    ui->Semesters->setLayout(layout2);
    connect(ui->pushButtonAdd_Semesters, &QPushButton::clicked, this, &MainWindow::addNewButton);

    // Oculta los botones "Unselect", "Remove" y "Duplicate" al inicio
    ui->pushButtonUnselect_Semesters->hide();
    ui->pushButtonRemove_Semesters->hide();
    ui->pushButtonDuplicate_Semesters->hide();

    connect(ui->pushButtonSelect_Semesters, &QPushButton::clicked, this, &MainWindow::enterSelectionMode);
    connect(ui->pushButtonUnselect_Semesters, &QPushButton::clicked, this, &MainWindow::exitSelectionMode);
    connect(ui->pushButtonRemove_Semesters, &QPushButton::clicked, this, &MainWindow::removeSelectedButtons);
    connect(ui->pushButtonDuplicate_Semesters, &QPushButton::clicked, this, &MainWindow::duplicateSelectedButtons);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSemesters_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_pushButtonTeachers_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_pushButton_HomeS_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeT_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButtonExternal_Courses_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_pushButtonCycles_clicked(){ui->stackedWidget->setCurrentIndex(4);}
void MainWindow::on_pushButtonCourses_clicked(){ui->stackedWidget->setCurrentIndex(5);}
void MainWindow::on_pushButtonClassrooms_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_pushButton_HomeEC_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCy_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCo_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_Cl_clicked(){ui->stackedWidget->setCurrentIndex(0);}

void MainWindow::addNewButton()
{
    dialog_wb dialog(this); // Crea una instancia de tu cuadro de diálogo personalizado
    if (dialog.exec() == QDialog::Accepted) { // Muestra el cuadro de diálogo y verifica si el usuario hizo clic en "Agregar"
        QString buttonName = dialog.getButtonName(); // Obtiene el nombre del botón ingresado por el usuario

        // Verifica si ya existe un botón con ese nombre
        bool exists = false;
        for (int i = 0; i < layout1->count(); ++i) {
            QPushButton *button = qobject_cast<QPushButton*>(layout1->itemAt(i)->widget());
            if (button && button->text() == buttonName) {
                exists = true;
                break;
            }
        }

        if (exists) {
            // Muestra un mensaje de error si el botón ya existe
            QMessageBox::warning(this, "Error:", "This element already exists.");
        } else {
            // Crea y agrega un nuevo botón
            QPushButton *newButton = new QPushButton(this);
            newButton->setText(buttonName);
            connect(newButton, &QPushButton::clicked, this, &MainWindow::buttonClicked);
            newButton->installEventFilter(this); // Instala un filtro de eventos para detectar el doble clic
            layout1->addWidget(newButton);
        }
    }
}


void MainWindow::enterSelectionMode()
{
    isSelectionMode = true;
    ui->pushButtonAdd_Semesters->hide();
    ui->pushButtonSelect_Semesters->hide();
    ui->pushButtonUnselect_Semesters->show();
    ui->pushButtonDuplicate_Semesters->show();
    ui->pushButtonRemove_Semesters->show();
}

void MainWindow::exitSelectionMode()
{
    isSelectionMode = false;
    ui->pushButtonAdd_Semesters->show();
    ui->pushButtonSelect_Semesters->show();
    ui->pushButtonUnselect_Semesters->hide();
    ui->pushButtonDuplicate_Semesters->hide();
    ui->pushButtonRemove_Semesters->hide();
}

void MainWindow::removeSelectedButtons()
{
    // Itera en reversa para no alterar el índice de los elementos restantes al eliminar
    for (int i = layout1->count() - 1; i >= 0; --i) {
        QPushButton *button = qobject_cast<QPushButton*>(layout1->itemAt(i)->widget());
        if (button && button->property("isSelected").toBool()) {
            // Remueve el botón del layout y lo elimina
            layout1->removeWidget(button);
            delete button;
        }
    }
}


void MainWindow::duplicateSelectedButtons()
{
    for (int i = 0; i < layout1->count(); ++i) {
        QPushButton *button = qobject_cast<QPushButton*>(layout1->itemAt(i)->widget());
        if (button && button->property("isSelected").toBool()) {
            QString originalName = button->text();
            QString newName = originalName;
            int duplicateCount = 1;

            // Verifica si ya existe un botón con ese nombre y ajusta el nombre del duplicado
            bool nameExists;
            do {
                nameExists = false;
                for (int j = 0; j < layout1->count(); ++j) {
                    QPushButton *otherButton = qobject_cast<QPushButton*>(layout1->itemAt(j)->widget());
                    if (otherButton && otherButton->text() == newName) {
                        nameExists = true;
                        newName = QString("%1 (%2)").arg(originalName).arg(duplicateCount++);
                        break;
                    }
                }
            } while (nameExists);

            // Crea y agrega un nuevo botón con el nombre ajustado
            QPushButton *newButton = new QPushButton(this);
            newButton->setText(newName);

            connect(newButton, &QPushButton::clicked, this, &MainWindow::buttonClicked);
            newButton->installEventFilter(this);

            layout1->addWidget(newButton);
        }
    }
}



void MainWindow::buttonClicked()
{
    if (!isSelectionMode) return; // Si no estamos en modo de selección, no hacemos nada

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    // Cambia el estado de selección del botón
    bool isSelected = button->property("isSelected").toBool();
    button->setProperty("isSelected", !isSelected);

    // Cambia el aspecto del botón para indicar si está seleccionado
    if (!isSelected) {
        button->setStyleSheet("background-color: #7dff33 ");
    } else {
        button->setStyleSheet("");
    }
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (!isSelectionMode && event->type() == QEvent::MouseButtonDblClick) {
        QPushButton *button = qobject_cast<QPushButton*>(watched);
        if (button) {
            // Si se hace click una vez por ahora ok
            bool ok;
            QString newName = QInputDialog::getText(this, tr("Edit Button Name"),
                                                     tr("Button name:"), QLineEdit::Normal,
                                                     button->text(), &ok);
            if (ok && !newName.isEmpty()) {
                button->setText(newName);
            }
            return true; // Indica que el evento fue manejado
        }
    }
    return QMainWindow::eventFilter(watched, event); // Llama a la implementación base
}