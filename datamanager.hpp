#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <QStringList>

#include "yearlysensortype.hpp"

class DataManager
{
public:
    DataManager();
    DataManager(QString fileName);
    QList<QString> getDataList() const;
    QList<QString> getDataListAfter(int const index) const;

    std::vector<YearlySensorType> data;
    QList<QString> dataList;
    void generateDataList();
    void setCommentText(QString fileName);
    void setWeatherData(QString fileName);
    YearlySensorType& inYear(int y);
    bool existYear(int const y) const;
};

#endif // DATAMANAGER_HPP
