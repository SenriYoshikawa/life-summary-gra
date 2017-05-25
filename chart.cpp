#include "chart.hpp"

#include <QDebug>
#include <QString>
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QLayout>
#include <QValueAxis>


QT_CHARTS_USE_NAMESPACE

Chart::Chart()
{
    this->setTitle("Graph!");
    this->setAnimationOptions(QChart::SeriesAnimations);

    this->legend()->setVisible(true);
    this->legend()->setAlignment(Qt::AlignBottom);

}

void Chart::setMonth(MontylySensorType data)
{

    QBarSet *s1Set = new QBarSet("Sensor1");
    QBarSet *s2Set = new QBarSet("Sensor2");


    for(auto const& each : data.monthlyData)
    {
        *s1Set << each.s1_sum;
        *s2Set << each.s2_sum;
    }

    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(s1Set);
    barSeries->append(s2Set);

    QLineSeries *lineSeries = new QLineSeries();
    lineSeries->setName("trend");
    lineSeries->append(QPoint(0, 5));
    lineSeries->append(QPoint(1, 10));
    lineSeries->append(QPoint(2, 15));
    lineSeries->append(QPoint(3, 20));
    lineSeries->append(QPoint(4, 25));
    lineSeries->append(QPoint(5, 30));

    QValueAxis *axisTempreture = new QValueAxis;
    axisTempreture->setRange(-10, 40);
    axisTempreture->setTickCount(11);

    QValueAxis *axisSensor = new QValueAxis;
    axisSensor->setRange(0, 2000);
    axisSensor->setTickCount(11);

    QStringList categories;
    for(auto const& each : data.monthlyData)
    {
        categories << QString::number(each.day) + "日";
    }
    QBarCategoryAxis *axisDays = new QBarCategoryAxis();
    axisDays->append(categories);

    lineSeries->attachAxis(axisDays);
    lineSeries->attachAxis(axisTempreture);

    barSeries->attachAxis(axisDays);
    barSeries->attachAxis(axisSensor);


    this->removeAllSeries();
    this->addSeries(barSeries);
    this->addSeries(lineSeries);


    //this->createDefaultAxes();
    this->setAxisX(axisDays, barSeries);
    this->setAxisY(axisSensor, barSeries);
    //this->setAxisY(axisTempreture, lineSeries);
    this->addAxis(axisTempreture, Qt::AlignRight);


}

void Chart::setTermMonth(DataManager const& dataManager, const int begin, const int length)
{
    QBarSet *s1Set = new QBarSet("Sensor1");
    QBarSet *s2Set = new QBarSet("Sensor2");
    QStringList categories;


    qDebug() << begin << length;
    int i = 0;
    for(auto const& each_year : dataManager.data) for(auto const& each_month : each_year.yearlyData)
    {
        if(begin <= i++ && i <= begin + length)
        {
            *s1Set << each_month.s1_sum;
            *s2Set << each_month.s2_sum;
            categories << QString::number(each_year.year) + "年" + QString::number(each_month.month) + "日";
        }
    }

    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(s1Set);
    barSeries->append(s2Set);


    this->removeAllSeries();
    this->addSeries(barSeries);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    this->createDefaultAxes();
    this->setAxisX(axis, barSeries);
}

