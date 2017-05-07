#ifndef YEARLYSENSORTYPE_H
#define YEARLYSENSORTYPE_H

#include <vector>

#include "montylysensortype.hpp"

class YearlySensorType
{
public:
    YearlySensorType();
    YearlySensorType(std::size_t const _year, std::vector<MontylySensorType> const _yearlyData);

    int const year;
    std::vector<MontylySensorType> const yearlyData;
};

#endif // YEARLYSENSORTYPE_H
