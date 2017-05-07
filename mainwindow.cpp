#include <QFileDialog>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QLayout>


#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "datamanager.hpp"
#include "chart.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //std::vector<YearlySensorType> data;
    DataManager* dataManager;


    connect(ui->actionOpen, QAction::triggered,[=,&dataManager](){
        QString fileName = QFileDialog::getOpenFileName(this,"データフィアルを選択","","Text File (*.txt *.csv)");
        dataManager = new DataManager(fileName);
        qDebug() << "read complete";

        ui->beginComboBox->addItems(dataManager->getDataList());
    });

    connect(ui->beginComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=,&dataManager](int index){
        while(ui->endComboBox->count() > 0)ui->endComboBox->removeItem(0);
        ui->endComboBox->addItems(dataManager->getDataListAfter(index));
        ui->drawButton->setEnabled(true);
    });

    connect(ui->drawButton, &QPushButton::clicked,[=,&dataManager](){
        QLayout *chartlay = new QHBoxLayout;
        qDebug() << "ok1";
        chartlay->addWidget(Chart::getChart(dataManager->data, ui->beginComboBox->currentIndex(), ui->endComboBox->currentIndex()));
        qDebug() << "ok2";
        ui->chartWidget->setLayout(chartlay);
        qDebug() << "ok3";
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
