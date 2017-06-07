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

    QLayout *threeHoursChartlay = new QHBoxLayout;
    Chart* threeHoursChart = new Chart();
    QChartView *threeHoursChartView = new QChartView(threeHoursChart);
    threeHoursChartlay->addWidget(threeHoursChartView);
    ui->threeHoursWidget->setLayout(threeHoursChartlay);

    connect(ui->actionSensorFileOpen, QAction::triggered,[=,&dataManager](){
        QString fileName = QFileDialog::getOpenFileName(this,"センサデータフィアルを選択","","Text File (*.txt *.csv)");
        dataManager = new DataManager(fileName);
        qDebug() << "senssor file read complete";

        ui->beginComboBox->addItems(dataManager->getDataList());
        ui->monthSelectComboBox->addItems(dataManager->getDataList());
        ui->actionCommentFileOpen->setEnabled(true);
        ui->actionWeatherFileOpen->setEnabled(true);
        QDate date(dataManager->data.at(0).year,
                   dataManager->data.at(0).yearlyData.at(0).month,
                   dataManager->data.at(0).yearlyData.at(0).monthlyData.at(0).day);
        ui->threeHoursDateEdit->setDate(date);
    });

    connect(ui->actionCommentFileOpen, QAction::triggered,[=,&dataManager](){
        QString fileName = QFileDialog::getOpenFileName(this,"コメントフィアルを選択","","Text File (*.txt *.csv)");
        dataManager->setCommentText(fileName);
        qDebug() << "comment file read complete";
    });

    connect(ui->actionWeatherFileOpen, QAction::triggered,[=,&dataManager](){
        QString fileName = QFileDialog::getOpenFileName(this,"気象データフィアルを選択","","Text File (*.txt *.csv)");
        dataManager->setWeatherData(fileName);
        qDebug() << "weather file read complete";
    });

    connect(ui->beginComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=,&dataManager](int index){
        while(ui->endComboBox->count() > 0)ui->endComboBox->removeItem(0);
        ui->endComboBox->addItems(dataManager->getDataListAfter(index));
        ui->drawButton->setEnabled(true);
    });

    connect(ui->drawButton, &QPushButton::clicked,[=,&dataManager](){
        termMonthChart->setTermMonth(*dataManager, ui->beginComboBox->currentIndex(), ui->endComboBox->currentIndex() + 1);
    });

    connect(ui->monthSelectComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=,&dataManager](){
        std::size_t year = ui->monthSelectComboBox->currentText().split("/").at(1).toInt();
        std::size_t month = ui->monthSelectComboBox->currentText().split("/").at(0).toInt();
        auto& targetMonth = dataManager->inYear(year).inMonth(month);

        aMonthChart->setMonth(targetMonth);
        ui->commentTextEdit->clear();
        ui->commentTextEdit->appendPlainText(targetMonth.getCommentStrings());
    });

    connect(ui->threeHoursDateEdit, &QDateEdit::dateChanged, [=,&dataManager](){
        /*
        qDebug() << ui->threeHoursDateEdit->date().day();
        qDebug() << ui->threeHoursDateEdit->date().month();
        qDebug() << ui->threeHoursDateEdit->date().year();
        */
        int year = ui->threeHoursDateEdit->date().year();
        int month = ui->threeHoursDateEdit->date().month();
        int day = ui->threeHoursDateEdit->date().day();


        if(dataManager->existYear(year) && dataManager->inYear(year).existMonth(month) && dataManager->inYear(year).inMonth(month).existDay(day))
        {
            threeHoursChart->set3HoursInADay(*dataManager, year, month, day);
        }
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
