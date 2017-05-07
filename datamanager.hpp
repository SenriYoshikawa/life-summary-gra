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

private:
    std::vector<YearlySensorType> data;
    QList<QString> dataList;
    void generateDataList();
};

#endif // DATAMANAGER_HPP
