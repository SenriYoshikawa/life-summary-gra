#include "amonthchart.hpp"

#include <QDebug>
#include <QString>
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QLayout>

AMonthChart::AMonthChart()
{
    this->setTitle("A month graph");
    this->setAnimationOptions(QChart::SeriesAnimations);

    this->legend()->setVisible(true);
    this->legend()->setAlignment(Qt::AlignBottom);

}

void AMonthChart::setMonth(MontylySensorType data)
{
    QT_CHARTS_USE_NAMESPACE
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


    this->removeAllSeries();
    this->addSeries(barSeries);

    QStringList categories;
    for(auto const& each : data.monthlyData)
    {
        categories << QString::number(each.day) + "日";
    }
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    this->createDefaultAxes();
    this->setAxisX(axis, barSeries);


}
