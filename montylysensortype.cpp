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
