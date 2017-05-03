#ifndef DAILYSENSORTYPE_HPP
#define DAILYSENSORTYPE_HPP

#include <vector>

#include "sensordatatype.hpp"

class DailySensorType
{
public:
    DailySensorType();
    DailySensorType(int const _day, std::vector<SensorDataType> const _dailyData);

private:
    int const day;
    std::vector<SensorDataType> const dailyData;
};

#endif // DAILYSENSORTYPE_HPP
