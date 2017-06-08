#ifndef DAILYSENSORTYPE_HPP
#define DAILYSENSORTYPE_HPP

#include <vector>

#include "sensordatatype.hpp"

class DailySensorType
{
public:
    DailySensorType();
    DailySensorType(int const _day, std::vector<SensorDataType> const _dailyData);

    double s1_sum = 0;
    double s2_sum = 0;
    double s1_ave = 0;
    double s2_ave = 0;
    int const day;
    std::vector<SensorDataType> const dailyData;
    std::vector<float> everyHourTemperature;
};

#endif // DAILYSENSORTYPE_HPP
