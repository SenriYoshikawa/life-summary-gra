#ifndef MONTYLYSENSORTYPE_HPP
#define MONTYLYSENSORTYPE_HPP

#include <vector>

#include "dailysensortype.hpp"

class MontylySensorType
{
public:
    MontylySensorType();
    MontylySensorType(int const _month, std::vector<DailySensorType> const _monthlyData);
    double s1_sum = 0;
    double s2_sum = 0;

    int const month;
    std::vector<DailySensorType> const monthlyData;
};

#endif // MONTYLYSENSORTYPE_HPP