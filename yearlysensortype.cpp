#include "yearlysensortype.hpp"

YearlySensorType::YearlySensorType()
{

}

YearlySensorType::YearlySensorType(const int _year, const std::vector<MontylySensorType> _yearlyData):year(_year),yearlyData(_yearlyData)
{

}
