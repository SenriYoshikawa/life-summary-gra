#include <QFileDialog>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QLayout>


#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "datamanager.hpp"
#include "chart_old.hpp"
#include "chart.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //std::vector<YearlySensorType> data;
    DataManager* dataManager;

    QLayout *chartlay = new QHBoxLayout;
    Chart* aMonthChart = new Chart();
    QChartView *aMonthChartView = new QChartView(aMonthChart);
    chartlay->addWidget(aMonthChartView);
    ui->aMonthChart->setLayout(chartlay);

    QLayout *termChartlay = new QHBoxLayout;
    Chart* termMonthChart = new Chart();
    QChartView *termMonthChartView = new QChartView(termMonthChart);
    termChartlay->addWidget(termMonthChartView);
    ui->chartWidget->setLayout(termChartlay);

    connect(ui->actionOpen, QAction::triggered,[=,&dataManager](){
        QString fileName = QFileDialog::getOpenFileName(this,"データフィアルを選択","","Text File (*.txt *.csv)");
        dataManager = new DataManager(fileName);
        qDebug() << "read complete";

        ui->beginComboBox->addItems(dataManager->getDataList());
        ui->monthSelectComboBox->addItems(dataManager->getDataList());
    });

    connect(ui->beginComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=,&dataManager](int index){
        while(ui->endComboBox->count() > 0)ui->endComboBox->removeItem(0);
        ui->endComboBox->addItems(dataManager->getDataListAfter(index));
        ui->drawButton->setEnabled(true);
    });

    connect(ui->drawButton, &QPushButton::clicked,[=,&dataManager](){
        termMonthChart->setTermMonth(*dataManager, ui->beginComboBox->currentIndex(), ui->beginComboBox->currentIndex());
        /*
        QLayout *chartlay = new QHBoxLayout;
        chartlay->addWidget(Chart::getChart(*dataManager, ui->beginComboBox->currentIndex(), ui->endComboBox->currentIndex()));
        ui->chartWidget->setLayout(chartlay);
        */
    });

    connect(ui->monthSelectComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=,&dataManager](){
        int i = 0;
        for(auto const& each_year : dataManager->data) for(auto const& each_month : each_year.yearlyData)
        {
            if(i++ == ui->monthSelectComboBox->currentIndex())
            {
                aMonthChart->setMonth(each_month);
                break;
            }
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
