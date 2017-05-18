#include "chart_old.hpp"
#include <QDebug>

ChartOld::ChartOld()
{

}

QtCharts::QChartView* ChartOld::getChart(DataManager &dataManager, int begin, int end)
{
    QT_CHARTS_USE_NAMESPACE

    //![1]
    QBarSet *s1Set = new QBarSet("Sensor1");
    QBarSet *s2Set = new QBarSet("Sensor2");

    int i = 0;
    for(auto const& each_year : dataManager.data)for(auto const& each_month : each_year.yearlyData)
    {
        if(begin <= i && i <= end)
        {
            *s1Set << each_month.s1_sum;
            *s2Set << each_month.s2_sum;
        }
        i++;
    }


    //![1]

    //![2]
    QBarSeries *series = new QBarSeries();
    series->append(s1Set);
    series->append(s2Set);

    //![2]

    //![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
    QStringList categories;
    for(std::size_t i = begin; i <= end; ++i)
    {
        categories << dataManager.getDataList().at(i);
    }
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    //![4]

    //![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //![6]

    return chartView;

}
