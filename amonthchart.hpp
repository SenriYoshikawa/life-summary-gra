#ifndef AMONTHCHART_HPP
#define AMONTHCHART_HPP

#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <QtCharts/QLineSeries>

#include "montylysensortype.hpp"

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class AMonthChart : public QChart
{
    Q_OBJECT
public:
    AMonthChart();
    void setMonth(MontylySensorType data);

};

#endif // AMONTHCHART_HPP
