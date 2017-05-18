#ifndef AMONTHCHART_HPP
#define AMONTHCHART_HPP

#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <QtCharts/QLineSeries>

#include "montylysensortype.hpp"
#include "datamanager.hpp"

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Chart : public QChart
{
    Q_OBJECT
public:
    Chart();
    void setMonth(MontylySensorType data);
    void setTermMonth(const DataManager &dataManager, int const begin, int const length);

};

#endif // AMONTHCHART_HPP
