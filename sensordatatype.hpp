#ifndef SENSORDATATYPE_HPP
#define SENSORDATATYPE_HPP

#include <cstddef>

class SensorDataType
{
public:
    SensorDataType();
    SensorDataType(std::size_t _hour, std::size_t _min, int _sensor1, int _sensor2);


private:
    std::size_t hour;
    std::size_t min;
    int sensor1;
    int sensor2;
};

#endif // SENSORDATATYPE_HPP
