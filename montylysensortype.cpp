#include "montylysensortype.hpp"
/*
MontylySensorType::MontylySensorType()
{

}
*/
MontylySensorType::MontylySensorType(const int _month, const std::vector<DailySensorType> _monthlyData):month(_month), monthlyData(_monthlyData)
{
    for(auto const& each_day : monthlyData)
    {
        s1_sum += each_day.s1_sum;
        s2_sum += each_day.s2_sum;
    }
    averageTemperature = std::vector<float> (31, 0);
}

QString MontylySensorType::getCommentStrings() const
{
    QString str;
    for(auto const& each : comment)
    {
        str += each;
        str += "\n";
    }
    return str;

}

bool MontylySensorType::existDay(std::size_t d) const
{
    if(monthlyData.size() >= d) return true;
    return false;
}

void MontylySensorType::generateTempreatureAverage()
{
    for(std::size_t i = 0; i < monthlyData.size(); ++i)
    {
        double sum = 0;
        for(auto const& each : monthlyData.at(i).everyHourTemperature)
        {
            sum += each;
        }
        averageTemperature[i] = sum / 24;
    }
}

