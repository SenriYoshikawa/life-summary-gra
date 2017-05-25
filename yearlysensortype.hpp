#ifndef YEARLYSENSORTYPE_H
#define YEARLYSENSORTYPE_H

#include <vector>

#include "montylysensortype.hpp"

class YearlySensorType
{
public:
    YearlySensorType();
    YearlySensorType(std::size_t const _year, std::vector<MontylySensorType> const _yearlyData);
    MontylySensorType &inMonth(int m);
    bool existMonth(int m);

    int const year;
    std::vector<MontylySensorType> yearlyData;
};

#endif // YEARLYSENSORTYPE_H
