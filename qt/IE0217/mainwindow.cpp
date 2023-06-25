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
    layout_Semesters = new QVBoxLayout;
    ui->scrollAreaWidget_Semesters->setLayout(layout_Semesters);
    QVBoxLayout *layout2 = new QVBoxLayout;
    ui->Semesters->setLayout(layout2);

    // Conectar botones para cada pestaña
    connectButtonsAndLayouts("Semesters");
    connectButtonsAndLayouts("Teachers");
    connectButtonsAndLayouts("ExternalCourses");
    connectButtonsAndLayouts("Cycles");
    connectButtonsAndLayouts("Courses");
    connectButtonsAndLayouts("Classrooms");

    // Ocultar botones al inicio
    hideButtons();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSemesters_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_pushButtonTeachers_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_pushButtonExternalCourses_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_pushButtonCycles_clicked(){ui->stackedWidget->setCurrentIndex(4);}
void MainWindow::on_pushButtonCourses_clicked(){ui->stackedWidget->setCurrentIndex(5);}
void MainWindow::on_pushButtonClassrooms_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_pushButton_HomeS_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeT_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeEC_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCy_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCo_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCl_clicked(){ui->stackedWidget->setCurrentIndex(0);}



void MainWindow::connectButtonsAndLayouts(const QString &tabName)
{

    QPushButton *buttonAdd = findChild<QPushButton*>(QString("pushButtonAdd_%1").arg(tabName));
    QPushButton *buttonSelect = findChild<QPushButton*>(QString("pushButtonSelect_%1").arg(tabName));
    QPushButton *buttonUnselect = findChild<QPushButton*>(QString("pushButtonUnselect_%1").arg(tabName));
    QPushButton *buttonRemove = findChild<QPushButton*>(QString("pushButtonRemove_%1").arg(tabName));
    QPushButton *buttonDuplicate = findChild<QPushButton*>(QString("pushButtonDuplicate_%1").arg(tabName));

    if (buttonAdd) connect(buttonAdd, &QPushButton::clicked, this, &MainWindow::addNewButton);
    if (buttonSelect) connect(buttonSelect, &QPushButton::clicked, this, &MainWindow::enterSelectionMode);
    if (buttonUnselect) connect(buttonUnselect, &QPushButton::clicked, this, &MainWindow::exitSelectionMode);
    if (buttonRemove) connect(buttonRemove, &QPushButton::clicked, this, &MainWindow::removeSelectedButtons);
    if (buttonDuplicate) connect(buttonDuplicate, &QPushButton::clicked, this, &MainWindow::duplicateSelectedButtons);
}

void MainWindow::hideButtons()
{
    const QStringList tabNames = {"Semesters", "Teachers", "ExternalCourses", "Cycles", "Courses", "Classrooms"};

    for (const QString &tabName : tabNames) {
        QPushButton *buttonUnselect = findChild<QPushButton*>(QString("pushButtonUnselect_%1").arg(tabName));
        QPushButton *buttonRemove = findChild<QPushButton*>(QString("pushButtonRemove_%1").arg(tabName));
        QPushButton *buttonDuplicate = findChild<QPushButton*>(QString("pushButtonDuplicate_%1").arg(tabName));

        if (buttonUnselect) buttonUnselect->hide();
        if (buttonRemove) buttonRemove->hide();
        if (buttonDuplicate) buttonDuplicate->hide();
    }
}


void MainWindow::addNewButton()
{
    dialog_wb dialog(this); // Crea una instancia de tu cuadro de diálogo personalizado
    if (dialog.exec() == QDialog::Accepted) { // Muestra el cuadro de diálogo y verifica si el usuario hizo clic en "Agregar"
        QString buttonName = dialog.getButtonName(); // Obtiene el nombre del botón ingresado por el usuario

        // Verifica si ya existe un botón con ese nombre
        bool exists = false;
        for (int i = 0; i < layout_Semesters->count(); ++i) {
            QPushButton *button = qobject_cast<QPushButton*>(layout_Semesters->itemAt(i)->widget());
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
            layout_Semesters->addWidget(newButton);
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
    for (int i = layout_Semesters->count() - 1; i >= 0; --i) {
        QPushButton *button = qobject_cast<QPushButton*>(layout_Semesters->itemAt(i)->widget());
        if (button && button->property("isSelected").toBool()) {
            // Remueve el botón del layout y lo elimina
            layout_Semesters->removeWidget(button);
            delete button;
        }
    }
}


void MainWindow::duplicateSelectedButtons()
{
    for (int i = 0; i < layout_Semesters->count(); ++i) {
        QPushButton *button = qobject_cast<QPushButton*>(layout_Semesters->itemAt(i)->widget());
        if (button && button->property("isSelected").toBool()) {
            QString originalName = button->text();
            QString newName = originalName;
            int duplicateCount = 1;

            // Verifica si ya existe un botón con ese nombre y ajusta el nombre del duplicado
            bool nameExists;
            do {
                nameExists = false;
                for (int j = 0; j < layout_Semesters->count(); ++j) {
                    QPushButton *otherButton = qobject_cast<QPushButton*>(layout_Semesters->itemAt(j)->widget());
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

            layout_Semesters->addWidget(newButton);
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