#include "sensordatatype.hpp"

SensorDataType::SensorDataType()
{

}

SensorDataType::SensorDataType(std::chrono::hours _hour, std::chrono::minutes _minute, int _sensor1, int _sensor2):hour(_hour),minute(_minute),sensor1(_sensor1),sensor2(_sensor2)
{

}

SensorDataType::SensorDataType(QString filename)
{

}
