#include <QFileDialog>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "datamanager.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<YearlySensorType> data;


    connect(ui->actionOpen, QAction::triggered,[=,&data](){
        QString fileName = QFileDialog::getOpenFileName(this,"データフィアルを選択","","Text File (*.txt *.csv)");
        DataManager dataManager(fileName);
        data = dataManager.getSensorData();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
