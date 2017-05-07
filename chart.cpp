#include "chart.hpp"
#include <QDebug>

Chart::Chart()
{

}

QtCharts::QChartView* Chart::getChart(std::vector<YearlySensorType> &yearlyData, int begin, int end)
{
    QT_CHARTS_USE_NAMESPACE

    //![1]
    QBarSet *s1Set = new QBarSet("Sensor1");
    QBarSet *s2Set = new QBarSet("Sensor2");

    int i = 0;
    for(auto const& each_year : yearlyData)for(auto const& each_month : each_year.yearlyData)
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
    // TODO: やる
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
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

    /*
    QtCharts::QBarSet barSet("test");

    int i = 0;
    for(auto const& each_year : yearlyData)for(auto const& each_month : each_year.yearlyData)
    {
        if(begin <= i && i <= end) barSet << each_month.s1_sum;
        i++;
    }

    qDebug() << "ok2-1";

    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    series->append(&barSet);

    qDebug() << "ok2-2";

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

    qDebug() << "ok2-3";

    QStringList categories;
    categories << "testAxis";
    QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    qDebug() << "ok2-4";

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    qDebug() << "ok2-5";

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    qDebug() << "ok2-6";

    return chartView;
    */
}
