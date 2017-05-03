#ifndef SENSORDATATYPE_HPP
#define SENSORDATATYPE_HPP

#include <chrono>

class SensorDataType
{
public:
    SensorDataType();
    SensorDataType(std::chrono::hours _hour, std::chrono::minutes _minute, int _sensor1, int _sensor2);


private:
    std::chrono::hours hour;
    std::chrono::minutes minute;
    int sensor1;
    int sensor2;
};

#endif // SENSORDATATYPE_HPP
