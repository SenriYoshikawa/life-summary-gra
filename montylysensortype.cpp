#include "montylysensortype.hpp"

MontylySensorType::MontylySensorType()
{

}

MontylySensorType::MontylySensorType(const int _month, const std::vector<DailySensorType> _monthlyData):month(_month), monthlyData(_monthlyData)
{

}
