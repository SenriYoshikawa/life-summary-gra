#include "dailysensortype.hpp"

/*
DailySensorType::DailySensorType()
{

}
*/
DailySensorType::DailySensorType(const int _day, const std::vector<SensorDataType> _dailyData):day(_day),dailyData(_dailyData)
{
    for(auto const& each : dailyData)
    {
        s1_sum += each.sensor1;
        s2_sum += each.sensor2;
    }
}
