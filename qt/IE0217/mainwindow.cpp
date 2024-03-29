#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog_wb.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <set>
#include <QDebug>
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isSelectionMode(false)
{
    ui->setupUi(this);
    layout_Semesters = new QVBoxLayout;
    ui->scrollAreaWidget_Semesters->setLayout(layout_Semesters);
    layout_Teachers = new QVBoxLayout;
    ui->scrollAreaWidget_Teachers->setLayout(layout_Teachers);
    layout_ExternalCourses = new QVBoxLayout;
    ui->scrollAreaWidget_ExternalCourses->setLayout(layout_ExternalCourses);
    layout_Cycles = new QVBoxLayout;
    ui->scrollAreaWidget_Cycles->setLayout(layout_Cycles);
    layout_Classrooms = new QVBoxLayout;
    ui->scrollAreaWidget_Classrooms->setLayout(layout_Classrooms);

    // Tabla CurrentSchedule
    QStringList headers_CurrentSchedule = {"Select", "Ciclo", "Sigla", "Nombre", "G", "Horario", "Aula", "Cupo", "Profesor", "Dept", "Observaciones", "Acción"};
    ui->scheduleTable_CurrentSchedule->setColumnCount(headers_CurrentSchedule.size());
    ui->scheduleTable_CurrentSchedule->setHorizontalHeaderLabels(headers_CurrentSchedule);
    connect(ui->pushButtonAdd_CurrentSchedule, &QPushButton::clicked, this, &MainWindow::addRowToCurrentSchedule);
    connect(ui->pushButtonRemove_CurrentSchedule, &QPushButton::clicked, this, &MainWindow::deleteSelectedRowsInCurrentSchedule);

    // Tabla Courses
    QStringList headers_Courses = {"Select", "Ciclo", "Sigla", "Nombre", "Departamento", "Acción"};
    ui->scheduleTable_Courses->setColumnCount(headers_Courses.size());
    ui->scheduleTable_Courses->setHorizontalHeaderLabels(headers_Courses);
    connect(ui->pushButtonAdd_Courses, &QPushButton::clicked, this, &MainWindow::addRowToCourses);
    connect(ui->pushButtonRemove_Courses, &QPushButton::clicked, this, &MainWindow::deleteSelectedRowsInCourses);



    // Conectar botones para cada pestaña
    connectButtons("Semesters");
    connectButtons("Teachers");
    connectButtons("ExternalCourses");
    connectButtons("Cycles");
    connectButtons("Classrooms");

    // Ocultar botones al inicio
    hideButtons();

    // Botón para addCSV
    connect(ui->pushButtonAddCSV_ScheduleGenerator, &QPushButton::clicked, this, &MainWindow::on_pushButtonAddCSV_ScheduleGenerator_clicked);

}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButtonSemesters_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_pushButtonTeachers_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_pushButtonExternalCourses_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_pushButtonCycles_clicked(){ui->stackedWidget->setCurrentIndex(4);}
void MainWindow::on_pushButtonCourses_clicked(){ui->stackedWidget->setCurrentIndex(5);}
void MainWindow::on_pushButtonClassrooms_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_pushButtonCurrentSchedule_clicked(){ui->stackedWidget->setCurrentIndex(7);}
void MainWindow::on_pushButtonScheduleGenerator_clicked(){ui->stackedWidget->setCurrentIndex(8);}
void MainWindow::on_pushButton_HomeS_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeT_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeEC_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCy_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCo_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCl_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCu_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeSG_clicked(){ui->stackedWidget->setCurrentIndex(0);}

void MainWindow::connectButtons(const QString &tabName) {

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

void MainWindow::hideButtons() {
    const QStringList tabNames = {"Semesters", "Teachers", "ExternalCourses", "Cycles", "Classrooms"};

    for (const QString &tabName : tabNames) {
        QPushButton *buttonUnselect = findChild<QPushButton*>(QString("pushButtonUnselect_%1").arg(tabName));
        QPushButton *buttonRemove = findChild<QPushButton*>(QString("pushButtonRemove_%1").arg(tabName));
        QPushButton *buttonDuplicate = findChild<QPushButton*>(QString("pushButtonDuplicate_%1").arg(tabName));

        if (buttonUnselect) buttonUnselect->hide();
        if (buttonRemove) buttonRemove->hide();
        if (buttonDuplicate) buttonDuplicate->hide();
    }
}


void MainWindow::addNewButton() {
    QVBoxLayout *currentLayout = getCurrentLayout(); // Obtiene el layout actual
    if (!currentLayout) return; // Si no hay un layout actual, sale de la función
    
    QString currentTabName = getTabNameFromLayout(currentLayout); // Obtiene el nombre de la pestaña actual
    
    dialog_wb dialog(this); 
    if (dialog.exec() == QDialog::Accepted) { // Muestra el cuadro de diálogo y verifica si el usuario hizo clic en "Agregar"
        QString buttonName = dialog.getButtonName(); // Obtiene el nombre del botón ingresado por el usuario

        // Verifica si ya existe un botón con ese nombre
        bool exists = false;
        for (int i = 0; i < currentLayout->count(); ++i) {
            QPushButton *button = qobject_cast<QPushButton*>(currentLayout->itemAt(i)->widget());
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
            currentLayout->addWidget(newButton);

            // Si la pestaña actual es "Teachers", crea un objeto Teacher y agrega al vector
            if (currentTabName == "Teachers") {
                Teacher teacher(buttonName.toStdString());
                teachers.push_back(teacher); 
                teacherIndices[newButton] = teachers.size() - 1; // Guarda el índice del nuevo profesor ya que estos botones no son listas, como los cursos o las filas. Entonces permite borrar los objetos de manera evificiente.
                for (const Teacher& teacher : teachers) {
                    qDebug()    << "Profesor: " << QString::fromStdString(teacher.nombre);
                }
            }

            // Si la pestaña actual es "Classrooms", crea un objeto Classroom y agrega al vector
            if (currentTabName == "Classrooms") {
                Classroom classroom(buttonName.toStdString());
                classrooms.push_back(classroom); 
                classroomIndices[newButton] = classrooms.size() - 1; // Guarda el índice del nuevo classroom ya que estos botones no son listas, como los cursos o las filas. Entonces permite borrar los objetos de manera evificiente.
            }
        }
    }
}





void MainWindow::enterSelectionMode()
{
    isSelectionMode = true;

    QVBoxLayout *currentLayout = getCurrentLayout(); // Obtiene el layout actual
    if (!currentLayout) return; // Si no hay un layout actual, sale de la función

    QString tabName = getTabNameFromLayout(currentLayout);

    // Buscar y acceder a los botones de la pestaña actual
    QPushButton *buttonAdd = findChild<QPushButton*>(QString("pushButtonAdd_%1").arg(tabName));
    QPushButton *buttonSelect = findChild<QPushButton*>(QString("pushButtonSelect_%1").arg(tabName));
    QPushButton *buttonUnselect = findChild<QPushButton*>(QString("pushButtonUnselect_%1").arg(tabName));
    QPushButton *buttonRemove = findChild<QPushButton*>(QString("pushButtonRemove_%1").arg(tabName));
    QPushButton *buttonDuplicate = findChild<QPushButton*>(QString("pushButtonDuplicate_%1").arg(tabName));

    // Ocultar/Mostrar botones
    if (buttonAdd) buttonAdd->hide();
    if (buttonSelect) buttonSelect->hide();
    if (buttonUnselect) buttonUnselect->show();
    if (buttonRemove) buttonRemove->show();
    if (buttonDuplicate) buttonDuplicate->show();
}

void MainWindow::exitSelectionMode()
{
    isSelectionMode = false;

    QVBoxLayout *currentLayout = getCurrentLayout(); // Obtiene el layout actual
    if (!currentLayout) return; // Si no hay un layout actual, sale de la función

    QString tabName = getTabNameFromLayout(currentLayout);

    // Buscar y acceder a los botones de la pestaña actual
    QPushButton *buttonAdd = findChild<QPushButton*>(QString("pushButtonAdd_%1").arg(tabName));
    QPushButton *buttonSelect = findChild<QPushButton*>(QString("pushButtonSelect_%1").arg(tabName));
    QPushButton *buttonUnselect = findChild<QPushButton*>(QString("pushButtonUnselect_%1").arg(tabName));
    QPushButton *buttonRemove = findChild<QPushButton*>(QString("pushButtonRemove_%1").arg(tabName));
    QPushButton *buttonDuplicate = findChild<QPushButton*>(QString("pushButtonDuplicate_%1").arg(tabName));

    // Mostrar/Ocultar botones
    if (buttonAdd) buttonAdd->show();
    if (buttonSelect) buttonSelect->show();
    if (buttonUnselect) buttonUnselect->hide();
    if (buttonRemove) buttonRemove->hide();
    if (buttonDuplicate) buttonDuplicate->hide();
}


void MainWindow::removeSelectedButtons() {
    QVBoxLayout *currentLayout = getCurrentLayout(); // Obtiene el layout actual
    if (!currentLayout) return; // Si no hay un layout actual, sale de la función

    QString currentTabName = getTabNameFromLayout(currentLayout); // Obtiene el nombre de la pestaña actual

    // Itera en reversa para no alterar el índice de los elementos restantes al eliminar
    for (int i = currentLayout->count() - 1; i >= 0; --i) {
        QPushButton *button = qobject_cast<QPushButton*>(currentLayout->itemAt(i)->widget());
        if (button && button->property("isSelected").toBool()) {
            // Elimina el objeto asociado al botón si la pestaña actual es "Teachers"
            if (currentTabName == "Teachers") {
                auto it = teacherIndices.find(button);
                if (it != teacherIndices.end()) {
                    int index = it.value();
                    teachers.erase(teachers.begin() + index); // Erase the teacher from the vector
                    teacherIndices.erase(it); // Erase the entry from the map

                    // Decrement the stored indices for all subsequent teachers
                    for (auto it = teacherIndices.begin(); it != teacherIndices.end(); ++it) {
                        if (it.value() > index) {
                            it.value() = it.value() - 1;
                        }
                    }
                }
            }

            if (currentTabName == "Classrooms") {
                auto it = classroomIndices.find(button);
                if (it != classroomIndices.end()) {
                    int index = it.value();
                    classrooms.erase(classrooms.begin() + index); // Erase the classroom from the vector
                    classroomIndices.erase(it); // Erase the entry from the map

                    // Decrement the stored indices for all subsequent classrooms
                    for (auto it = classroomIndices.begin(); it != classroomIndices.end(); ++it) {
                        if (it.value() > index) {
                            it.value() = it.value() - 1;
                        }
                    }
                }
            }
            // Remueve el botón del layout y lo elimina
            currentLayout->removeWidget(button);
            delete button;
        }
    }
}



void MainWindow::duplicateSelectedButtons() {
    QVBoxLayout *currentLayout = getCurrentLayout(); // Obtiene el layout actual
    if (!currentLayout) return; // Si no hay un layout actual, sale de la función
    
    QString currentTabName = getTabNameFromLayout(currentLayout); // Obtiene el nombre de la pestaña actual
    
    for (int i = 0; i < currentLayout->count(); ++i) {
        QPushButton *button = qobject_cast<QPushButton*>(currentLayout->itemAt(i)->widget());
        if (button && button->property("isSelected").toBool()) {
            QString originalName = button->text();
            QString newName = originalName;
            int duplicateCount = 1;

            // Verifica si ya existe un botón con ese nombre y ajusta el nombre del duplicado
            bool nameExists;
            do {
                nameExists = false;
                for (int j = 0; j < currentLayout->count(); ++j) {
                    QPushButton *otherButton = qobject_cast<QPushButton*>(currentLayout->itemAt(j)->widget());
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

            currentLayout->addWidget(newButton);
            
            // Crea y agrega un nuevo objeto si la pestaña actual es "Teachers"
            if (currentTabName == "Teachers") {
                Teacher teacher(newName.toStdString());
                teachers.push_back(teacher);
                teacherIndices.insert(newButton, teachers.size() - 1);
            }

            // Similar logic for "Classrooms"
            if (currentTabName == "Classrooms") {
                Classroom classroom(newName.toStdString());
                classrooms.push_back(classroom);
                classroomIndices.insert(newButton, classrooms.size() - 1);
            }
        }
    }
}



void MainWindow::buttonClicked() {
    if (!isSelectionMode) return; // Si no estamos en modo de selección, no hacemos nada

    QPushButton *button = qobject_cast<QPushButton*>(sender()); 
    if (!button) return;

    // Cambia el estado de selección del botón
    bool isSelected = button->property("isSelected").toBool();
    button->setProperty("isSelected", !isSelected);

    // Cambia el aspecto del botón para indicar si está seleccionado
    if (!isSelected) {
        button->setStyleSheet("background-color: #3eb900 ");
    } else {
        button->setStyleSheet("");
    }
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (!isSelectionMode && event->type() == QEvent::MouseButtonDblClick) {
        QPushButton *button = qobject_cast<QPushButton*>(watched);
        if (button) {
            // Si se hace click una vez por ahora ok
            bool ok;
            QString newName = QInputDialog::getText(this, tr("Edit Button Name"),
                                                     tr("Write down the name:"), 
                                                     QLineEdit::Normal,
                                                     button->text(), &ok);
            if (ok && !newName.isEmpty()) {
                button->setText(newName);
            }
            return true; // Indica que el evento fue manejado
        }
    }
    return QMainWindow::eventFilter(watched, event); // Llama a la implementación base
}


QVBoxLayout* MainWindow::getCurrentLayout() {
    int currentIndex = ui->stackedWidget->currentIndex();
    
    switch(currentIndex) {
        case 1:
            return layout_Semesters;
        case 2:
            return layout_Teachers;
        case 3:
            return layout_ExternalCourses;
        case 4:
            return layout_Cycles;
        case 5:
            return layout_Courses;
        case 6:
            return layout_Classrooms;
        default:
            return nullptr;
    }
}

QString MainWindow::getTabNameFromLayout(QVBoxLayout *layout) {
    if (layout == layout_Semesters) {
        return "Semesters";
    } else if (layout == layout_Teachers) {
        return "Teachers";
    } else if (layout == layout_ExternalCourses) {
        return "ExternalCourses";
    } else if (layout == layout_Cycles) {
        return "Cycles";
    } else if (layout == layout_Courses) {
        return "Courses";
    } else if (layout == layout_Classrooms) {
        return "Classrooms";
    } else {
        return QString();
    }
}




void MainWindow::addRowToCurrentSchedule() {
    int newRow = ui->scheduleTable_CurrentSchedule->rowCount();
    ui->scheduleTable_CurrentSchedule->insertRow(newRow);

    // Columna para casillas de verificación
    QCheckBox *checkBox = new QCheckBox(this);
    ui->scheduleTable_CurrentSchedule->setCellWidget(newRow, 0, checkBox);

    for (int col = 1; col < ui->scheduleTable_CurrentSchedule->columnCount() - 1; ++col) {
        if (col == 1 /* Cclo */ || col == 2 /* Sgla */ || col == 3 /* Nomb */ || col == 6 /* Aula */ || col == 8 /* Prof */ ||  col == 9 /* Dpt */) {
            QComboBox *comboBox = new QComboBox(this);
            comboBox->setEditable(true); // Permitir la entrada de texto

            connect(comboBox, &QComboBox::currentTextChanged, this, &MainWindow::editComboBoxTextInCurrentSchedule); // Edición de texto, color

            comboBox->addItem("");

            if (col == 1 /* Ciclo */ || col == 11 /* Departamento */) {
                connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateCourseOptionsOnCycleOrDepartmentChange(int)));
            } else if (col == 2 /* Sigla */ || col == 3 /* Nombre */) {
                connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateCourseOptionsOnSiglaOrNameChange(int)));
            }

            switch (col) {
                case 1: // Ciclo
                    for (const Curso& curso : cursos) {
                        comboBox->addItem(QString::fromStdString(curso.ciclo));
                    }
                    break;
                case 2: // Sigla
                    for (const Curso& curso : cursos) {
                        comboBox->addItem(QString::fromStdString(curso.sigla));
                    }
                    break;
                case 3: // Nombre
                    for (const Curso& curso : cursos) {
                        comboBox->addItem(QString::fromStdString(curso.nombre));
                    }
                    break;
                case 6: // Aula
                    for (const Classroom& classroom : classrooms) {
                        comboBox->addItem(QString::fromStdString(classroom.numeroAula));
                    }
                    break;
                case 8: // Profesor
                    for (const Teacher& teacher : teachers) {
                        comboBox->addItem(QString::fromStdString(teacher.nombre));
                    }
                    break;
                case 9: // Departamento
                    for (const Curso& curso : cursos) {
                        comboBox->addItem(QString::fromStdString(curso.departamento));
                    }
                    break;
            }

            ui->scheduleTable_CurrentSchedule->setCellWidget(newRow, col, comboBox);
        } else {
            QLineEdit *lineEdit = new QLineEdit(this);
            connect(lineEdit, &QLineEdit::textEdited, this, &MainWindow::editTextInCurrentSchedule);
            ui->scheduleTable_CurrentSchedule->setCellWidget(newRow, col, lineEdit);
        }
    }

    // Columna de botón Guardar
    QPushButton *saveButton = new QPushButton("Guardar", this);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveRowInCurrentSchedule);
    ui->scheduleTable_CurrentSchedule->setCellWidget(newRow, ui->scheduleTable_CurrentSchedule->columnCount() - 1, saveButton);
}





// Las siguientes 2 funciones seimplementarán más fácil cuando se separe los ciclos de los cursos como objetos contenedores. Para el proyecto se propone como beta. 
void MainWindow::updateCourseOptionsOnSiglaOrNameChange(int index) {
    QComboBox *combo = qobject_cast<QComboBox *>(sender());
    if (!combo) {
        qDebug() << "Combo sender not found, returning";
        return;
    }

    if (index < 0 || index >= cursos.size()) {
        qDebug() << "Invalid index, returning";
        return;
    }

    Curso selectedCourse = cursos[index];
    qDebug() << "Selected course: " << QString::fromStdString(selectedCourse.sigla);

    QPoint comboPos = combo->mapToParent(QPoint(0,0));
    qDebug() << "Combo position: " << comboPos;

    int rowIndex = ui->scheduleTable_CurrentSchedule->indexAt(comboPos).row();
    qDebug() << "Row index: " << rowIndex;

    if (rowIndex < 0) {
        qDebug() << "Invalid row index, returning";
        return;
    }

    QComboBox *cicloCombo = qobject_cast<QComboBox *>(ui->scheduleTable_CurrentSchedule->cellWidget(rowIndex, 1));
    QComboBox *siglaCombo = qobject_cast<QComboBox *>(ui->scheduleTable_CurrentSchedule->cellWidget(rowIndex, 2));
    QComboBox *nombreCombo = qobject_cast<QComboBox *>(ui->scheduleTable_CurrentSchedule->cellWidget(rowIndex, 3));
    QComboBox *departamentoCombo = qobject_cast<QComboBox *>(ui->scheduleTable_CurrentSchedule->cellWidget(rowIndex, 11));

    if (!cicloCombo || !siglaCombo || !nombreCombo || !departamentoCombo) {
        qDebug() << "Could not find all combo boxes, returning";
        return;
    }

    cicloCombo->blockSignals(true);
    siglaCombo->blockSignals(true);
    nombreCombo->blockSignals(true);
    departamentoCombo->blockSignals(true);

    cicloCombo->setCurrentText(QString::fromStdString(selectedCourse.ciclo));
    siglaCombo->setCurrentText(QString::fromStdString(selectedCourse.sigla));
    nombreCombo->setCurrentText(QString::fromStdString(selectedCourse.nombre));
    departamentoCombo->setCurrentText(QString::fromStdString(selectedCourse.departamento));

    cicloCombo->blockSignals(false);
    siglaCombo->blockSignals(false);
    nombreCombo->blockSignals(false);
    departamentoCombo->blockSignals(false);
}




void MainWindow::updateCourseOptionsOnCycleOrDepartmentChange(int index) {
    QComboBox *combo = qobject_cast<QComboBox *>(sender());
    if (!combo) return;

    QString selectedText = combo->itemText(index);

    std::set<std::string> uniqueSiglas;
    std::set<std::string> uniqueNombres;

    for (const Curso& curso : cursos) {
        if (selectedText.isEmpty() || curso.ciclo == selectedText.toStdString() || curso.departamento == selectedText.toStdString()) {
            uniqueSiglas.insert(curso.sigla);
            uniqueNombres.insert(curso.nombre);
        }
    }

    int rowIndex = ui->scheduleTable_CurrentSchedule->indexAt(combo->pos()).row();

    if (rowIndex < 0) return;

    QComboBox *siglaCombo = qobject_cast<QComboBox *>(ui->scheduleTable_CurrentSchedule->cellWidget(rowIndex, 2));
    QComboBox *nombreCombo = qobject_cast<QComboBox *>(ui->scheduleTable_CurrentSchedule->cellWidget(rowIndex, 3));

    if (!siglaCombo || !nombreCombo) return;

    siglaCombo->blockSignals(true);
    nombreCombo->blockSignals(true);

    siglaCombo->clear();
    nombreCombo->clear();

    for (const auto& sigla : uniqueSiglas) {
        siglaCombo->addItem(QString::fromStdString(sigla));
    }

    for (const auto& nombre : uniqueNombres) {
        nombreCombo->addItem(QString::fromStdString(nombre));
    }

    siglaCombo->blockSignals(false);
    nombreCombo->blockSignals(false);
}





















void MainWindow::editComboBoxTextInCurrentSchedule() {
    // Aquí, cambia el color de fondo de la celda del QComboBox a amarillo
    QComboBox* comboBoxSender = qobject_cast<QComboBox*>(sender());
    if (comboBoxSender) {
        comboBoxSender->setStyleSheet("background-color: yellow;");
    }
}


// Edición de fila en tab CurrentSchedule
void MainWindow::editTextInCurrentSchedule() {
    QLineEdit* lineEditSender = qobject_cast<QLineEdit*>(sender());
    if (!lineEditSender) return;

    // Encuentra la fila que contiene el QLineEdit que emitió la señal
    int editedRow = -1;
    for (int row = 0; row < ui->scheduleTable_CurrentSchedule->rowCount(); ++row) {
        for (int col = 1; col < ui->scheduleTable_CurrentSchedule->columnCount() - 1; ++col) {
            if (ui->scheduleTable_CurrentSchedule->cellWidget(row, col) == lineEditSender) {
                editedRow = row;
                break;
            }
        }
        if (editedRow != -1) break;
    }

    // Cambia el color de fondo de la fila a amarillo para indicar que ha sido editada
    if (editedRow != -1) {
        for (int col = 1; col < ui->scheduleTable_CurrentSchedule->columnCount() - 1; ++col) {
            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(ui->scheduleTable_CurrentSchedule->cellWidget(editedRow, col));
            if (lineEdit) { // Verifica que el casting fue exitoso
                lineEdit->setStyleSheet("background-color: yellow");
            }
        }
    }
}

void MainWindow::deleteSelectedRowsInCurrentSchedule() {
    // Recorrer las filas en reversa para evitar problemas al eliminar varias filas
    for (int row = ui->scheduleTable_CurrentSchedule->rowCount() - 1; row >= 0; --row) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->scheduleTable_CurrentSchedule->cellWidget(row, 0));
        if (checkBox && checkBox->isChecked()) {
            // Verificar si el índice está dentro del rango de la lista 'filas'
            if (row < filas.size()) {
                // Eliminar el objeto Curso correspondiente de la lista de filas
                filas.erase(filas.begin() + row);
            }
            // Eliminar la fila de la tabla
            ui->scheduleTable_CurrentSchedule->removeRow(row);
        }
    }
}

// Guardar fila en tab CurrentSchedule
void MainWindow::saveRowInCurrentSchedule() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    if (!buttonSender) return;

    int rowToSave = -1;
    for (int row = 0; row < ui->scheduleTable_CurrentSchedule->rowCount(); ++row) {
        if (ui->scheduleTable_CurrentSchedule->cellWidget(row, ui->scheduleTable_CurrentSchedule->columnCount() - 1) == buttonSender) {
            rowToSave = row;
            break;
        }
    }

    if (rowToSave == -1) return;


    // Obtener texto para Sigla (QComboBox)
    QComboBox *comboCiclo = qobject_cast<QComboBox*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 1));
    QString ciclo = comboCiclo ? comboCiclo->currentText() : QString();


    // Obtener texto para Sigla (QComboBox)
    QComboBox *comboSigla = qobject_cast<QComboBox*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 2));
    QString sigla = comboSigla ? comboSigla->currentText() : QString();

    // Obtener texto para Nombre (QComboBox)
    QComboBox *comboNombre = qobject_cast<QComboBox*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 3));
    QString nombrecurso = comboNombre ? comboNombre->currentText() : QString();

    QString grupo = qobject_cast<QLineEdit*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 4))->text();



    QString horarioc = qobject_cast<QLineEdit*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 5))->text();

    // Dividir el texto de horarioc usando 'y' como separador
    QStringList horarioSegments = horarioc.split("y", QString::SkipEmptyParts);

    // Interpretar cada segmento y crear objetos Horario
    std::vector<Horario> horarios;
    QRegularExpression horarioRegex(R"(([A-Z]): (\d{2}:\d{2}) a (\d{2}:\d{2}))");

    for (const QString &segment : horarioSegments) {
        QRegularExpressionMatch match = horarioRegex.match(segment.trimmed());

        if (match.hasMatch()) {
            QString dia = match.captured(1);
            QString horaInicio = match.captured(2);
            QString horaFinal = match.captured(3);

            // Crear el objeto Horario y agregarlo a horarios
            horarios.push_back(Horario(dia.toStdString(), horaInicio.toStdString(), horaFinal.toStdString()));
        } else {
            QMessageBox::warning(this, "Error", "El formato del horario es incorrecto. L: 18:00 a 21:50 y M: 18:00 a 21:50 es un formato de horario válido, por ejemplo.");
            return;
        }
    }

    // Obtener texto para Aula (QComboBox)
    QComboBox *comboAula = qobject_cast<QComboBox*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 6));
    QString aula = comboAula ? comboAula->currentText() : QString();

    QString cupo = qobject_cast<QLineEdit*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 7))->text();

    // Obtener texto para Profesor (QComboBox)
    QComboBox *comboProfesor = qobject_cast<QComboBox*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 8));
    QString profesor = comboProfesor ? comboProfesor->currentText() : QString();


    // Obtener texto para Departamento (QComboBox)
    QComboBox *comboDepartamento = qobject_cast<QComboBox*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 9));
    QString departamento = comboDepartamento ? comboDepartamento->currentText() : QString();

    QString observaciones = qobject_cast<QLineEdit*>(ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, 10))->text();

    // Validar que las celdas no estén vacías
    if (ciclo.isEmpty() || sigla.isEmpty() || nombrecurso.isEmpty() || grupo.isEmpty() || horarioc.isEmpty() || aula.isEmpty() || cupo.isEmpty() || profesor.isEmpty() || departamento.isEmpty() || observaciones.isEmpty()) {
        QMessageBox::warning(this, "Error", "Campos vacíos.");
        return;
    }

    static std::unordered_map<int, int> rowToIndexMap;

    // Actualizar el objeto existente o crear uno nuevo
    if (rowToIndexMap.find(rowToSave) != rowToIndexMap.end()) {
        // Actualizar el objeto existente
        int indexInFilas = rowToIndexMap[rowToSave];
        filas[indexInFilas] = Fila(ciclo.toStdString(), sigla.toStdString(), nombrecurso.toStdString(), grupo.toStdString(), horarios, aula.toStdString(), cupo.toStdString(), profesor.toStdString(), departamento.toStdString(), observaciones.toStdString());
    } else {
        // Crear un nuevo objeto y almacenar su índice
        filas.push_back(Fila(ciclo.toStdString(), sigla.toStdString(), nombrecurso.toStdString(), grupo.toStdString(), horarios, aula.toStdString(), cupo.toStdString(), profesor.toStdString(), departamento.toStdString(), observaciones.toStdString()));
        rowToIndexMap[rowToSave] = filas.size() - 1;
    }


    // Regresar color
    for (int col = 1; col < ui->scheduleTable_CurrentSchedule->columnCount(); ++col) {
        QWidget *cellWidget = ui->scheduleTable_CurrentSchedule->cellWidget(rowToSave, col);
        if (cellWidget) {
        cellWidget->setStyleSheet("background-color: none;");
        }
    }

    // Imprimir el contenido de todos los objetos Fila en terminal
    for (const Fila& fila : filas) {
        QString horarioStr;
        
        // Iterar sobre el vector de Horario y construir una cadena
        for (const Horario& horario : fila.horarios) {
            horarioStr += QString("%1: %2 a %3, ")
                    .arg(QString::fromStdString(horario.dia))
                    .arg(QString::fromStdString(horario.horaInicio))
                    .arg(QString::fromStdString(horario.horaFinal));
        }
        
        // Remover la última coma y espacio
        if (!horarioStr.isEmpty()) {
            horarioStr.chop(2);
        }

        // Imprimir la fila
        qDebug() << "Ciclo: " << QString::fromStdString(fila.ciclo)
                 << ", Sigla: " << QString::fromStdString(fila.sigla)
                 << ", Nombre: " << QString::fromStdString(fila.nombrecurso)
                 << ", Grupo: " << QString::fromStdString(fila.grupo)
                 << ", Horario: " << horarioStr
                 << ", Aula: " << QString::fromStdString(fila.aula)
                 << ", Cupo: " << QString::fromStdString(fila.cupo)
                 << ", Profesor: " << QString::fromStdString(fila.profesor)
                 << ", Departamento: " << QString::fromStdString(fila.departamento)
                 << ", Observaciones: " << QString::fromStdString(fila.observaciones);
    }
}



// Para tab Courses
void MainWindow::addRowToCourses() {
    int newRow = ui->scheduleTable_Courses->rowCount();
    ui->scheduleTable_Courses->insertRow(newRow);

    // Columna para casillas de verificación
    QCheckBox *checkBox = new QCheckBox(this);
    ui->scheduleTable_Courses->setCellWidget(newRow, 0, checkBox);

    for (int col = 1; col < ui->scheduleTable_Courses->columnCount() - 1; ++col) {
        QLineEdit *lineEdit = new QLineEdit(this);
        connect(lineEdit, &QLineEdit::textEdited, this, &MainWindow::editTextInCourses);
        ui->scheduleTable_Courses->setCellWidget(newRow, col, lineEdit);
    }

    // Columna de botón Guardar
    QPushButton *saveButton = new QPushButton("Guardar", this);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveRowInCourses);
    ui->scheduleTable_Courses->setCellWidget(newRow, ui->scheduleTable_Courses->columnCount() - 1, saveButton);
}

// Edición de fila en tab Courses
void MainWindow::editTextInCourses() {
    QLineEdit* lineEditSender = qobject_cast<QLineEdit*>(sender());
    if (!lineEditSender) return;

    // Encuentra la fila que contiene el QLineEdit que emitió la señal
    int editedRow = -1;
    for (int row = 0; row < ui->scheduleTable_Courses->rowCount(); ++row) {
        for (int col = 1; col < ui->scheduleTable_Courses->columnCount() - 1; ++col) {
            if (ui->scheduleTable_Courses->cellWidget(row, col) == lineEditSender) {
                editedRow = row;
                break;
            }
        }
        if (editedRow != -1) break;
    }

    // Cambia el color de fondo de la fila a amarillo para indicar que ha sido editada
    if (editedRow != -1) {
        for (int col = 1; col < ui->scheduleTable_Courses->columnCount() - 1; ++col) {
            qobject_cast<QLineEdit*>(ui->scheduleTable_Courses->cellWidget(editedRow, col))->setStyleSheet("background-color: yellow");
        }
    }
}



void MainWindow::deleteSelectedRowsInCourses() {
    // Recorrer las filas en reversa para evitar problemas al eliminar varias filas
    for (int row = ui->scheduleTable_Courses->rowCount() - 1; row >= 0; --row) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->scheduleTable_Courses->cellWidget(row, 0));
        if (checkBox && checkBox->isChecked()) {
            // Verificar si el índice está dentro del rango de la lista 'filas'
            if (row < filas.size()) {
                // Eliminar el objeto Curso correspondiente de la lista de filas
                filas.erase(filas.begin() + row);
            }
            // Eliminar la fila de la tabla
            ui->scheduleTable_Courses->removeRow(row);
        }
    }
}



// Guardar fila en tab Courses
void MainWindow::saveRowInCourses() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    if (!buttonSender) return;

    int rowToSave = -1;
    for (int row = 0; row < ui->scheduleTable_Courses->rowCount(); ++row) {
        if (ui->scheduleTable_Courses->cellWidget(row, ui->scheduleTable_Courses->columnCount() - 1) == buttonSender) {
            rowToSave = row;
            break;
        }
    }

    if (rowToSave == -1) return;

    QString ciclo = qobject_cast<QLineEdit*>(ui->scheduleTable_Courses->cellWidget(rowToSave, 1))->text();
    QString sigla = qobject_cast<QLineEdit*>(ui->scheduleTable_Courses->cellWidget(rowToSave, 2))->text();
    QString nombre = qobject_cast<QLineEdit*>(ui->scheduleTable_Courses->cellWidget(rowToSave, 3))->text();
    QString departamento = qobject_cast<QLineEdit*>(ui->scheduleTable_Courses->cellWidget(rowToSave, 4))->text();

    // Validar que las celdas no estén vacías
    if (ciclo.isEmpty() || sigla.isEmpty() || nombre.isEmpty() || departamento.isEmpty()) {
        QMessageBox::warning(this, "Error", "Campos vacíos.");
        return;
    }

    static std::unordered_map<int, int> rowToIndexMap;

    // Validar que no exista un curso con la misma sigla o nombre
    int indexInCursos = -1;
    if (rowToIndexMap.find(rowToSave) != rowToIndexMap.end()) {
        indexInCursos = rowToIndexMap[rowToSave];
    }

    for (int i = 0; i < cursos.size(); ++i) {
        const Curso& curso = cursos[i];
        if ((curso.sigla == sigla.toStdString() || curso.nombre == nombre.toStdString()) && i != indexInCursos) {
            QMessageBox::warning(this, "Error", "Ya existe un curso con la misma sigla o nombre.");
            return;
        }
    }

    // Actualizar el objeto existente o crear uno nuevo
    if (rowToIndexMap.find(rowToSave) != rowToIndexMap.end()) {
        // Actualizar el objeto existente
        int indexInCursos = rowToIndexMap[rowToSave];
        cursos[indexInCursos] = Curso(ciclo.toStdString(), sigla.toStdString(), nombre.toStdString(), departamento.toStdString());
    } else {
        // Crear un nuevo objeto y almacenar su índice
        cursos.push_back(Curso(ciclo.toStdString(), sigla.toStdString(), nombre.toStdString(), departamento.toStdString()));
        rowToIndexMap[rowToSave] = cursos.size() - 1;
    }

    for (int col = 1; col < ui->scheduleTable_Courses->columnCount(); ++col) {
        QWidget *cellWidget = ui->scheduleTable_Courses->cellWidget(rowToSave, col);
        if (cellWidget) {
            cellWidget->setStyleSheet("background-color: none;"); 
        }
    }

    // Imprimir el contenido de todos los objetos Curso en terminal
    for (const Curso& curso : cursos) {
        qDebug()    << "Ciclo: " << QString::fromStdString(curso.ciclo)
                    << ", Sigla: " << QString::fromStdString(curso.sigla)
                    <<", Nombre: " << QString::fromStdString(curso.nombre)
                    << ", Departamento: " << QString::fromStdString(curso.departamento);
    }
}


void MainWindow::on_pushButtonAddCSV_ScheduleGenerator_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open CSV"), "", tr("CSV Files (*.csv)"));

    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        // Leer los cursos desde el archivo CSV.
        QList<Cursog> cursos = leerCursosDesdeCSV(fileName);

        // Generar los CSV para los cursos.
        generarCSVsParaCursos(cursos);

        // Informar al usuario que la operación se ha completado.
        QMessageBox::information(this, tr("Operation Completed"), tr("The operation has completed."));
    }
}
