#include <QDebug>
#include "yearlysensortype.hpp"
/*
YearlySensorType::YearlySensorType()
{

}
*/
YearlySensorType::YearlySensorType(const std::size_t _year, const std::vector<MontylySensorType> _yearlyData):year(_year),yearlyData(_yearlyData)
{

}

MontylySensorType &YearlySensorType::inMonth(int m)
{
    for(std::size_t i = 0; i < yearlyData.size(); ++i)
    {
        if(yearlyData[i].month == m) return yearlyData[i];
    }
    qDebug() << m << "did not found in" << year << "data";
    return yearlyData[0];
}

bool YearlySensorType::existMonth(int m)
{
    for(std::size_t i = 0; i < yearlyData.size(); ++i)
    {
        if(yearlyData[i].month == m) return true;
    }
    return false;
}
