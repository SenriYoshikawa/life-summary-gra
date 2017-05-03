#include <QFileDialog>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "sensordatatype.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SensorDataType* data;

    connect(ui->actionOpen, QAction::triggered,[=,&data](){
        QString filename = QFileDialog::getOpenFileName(this,"データフィアルを選択","","Text File (*.txt *.csv)");
        data = new SensorDataType(filename);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
