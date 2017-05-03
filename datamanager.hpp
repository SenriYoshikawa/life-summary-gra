#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <QString>

#include "yearlysensortype.hpp"

class DataManager
{
public:
    DataManager();
    DataManager(QString fileName);
    std::vector<YearlySensorType> getSensorData();
};

#endif // DATAMANAGER_HPP
