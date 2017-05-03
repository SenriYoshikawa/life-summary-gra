#include "dailysensortype.hpp"

DailySensorType::DailySensorType()
{

}

DailySensorType::DailySensorType(const int _day, const std::vector<SensorDataType> _dailyData):day(_day),dailyData(_dailyData)
{

}
