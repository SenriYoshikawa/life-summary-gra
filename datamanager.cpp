#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>

#include "datamanager.hpp"

DataManager::DataManager()
{

}

DataManager::DataManager(QString fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "can not open" << fileName;
    }

    QTextStream in(&file);
    QString str;
    QStringList list;
    QList<QString> date;
    int s1;
    int s2;
    std::size_t h = 0;
    std::size_t m = 0;
    std::size_t day = 0, month = 0, year = 0;
    std::vector<SensorDataType> dailyTemp;
    dailyTemp.reserve(1440);
    std::vector<DailySensorType> monthlyTemp;
    monthlyTemp.reserve(12);
    std::vector<MontylySensorType> yearlyTemp;

    qDebug() << "ok";
    while(file.atEnd() == false)
    {
        qDebug() << year << " " << month << " " << day;
        while(file.atEnd() == false) // 1日のデータセットを作る　1440回ループ
        {
            str = in.readLine();
            list = str.split(',');
            h = list.at(1).split(':').at(0).toInt();
            m = list.at(1).split(':').at(1).toInt();

            s1 = (list.at(2) == 'x') ? 0 : list.at(2).toInt(0, 16);
            s2 = (list.at(3) == 'x') ? 0 : list.at(2).toInt(0, 16);
            dailyTemp.emplace_back(SensorDataType(h, m, s1, s2));
            //qDebug() << h << m;
            if(h == 23 && m == 59) break;
        }

        date = list.at(0).split('-');
        day = date.at(2).toInt();

        if(dailyTemp.size() != 1 && day == 1)
        {
            // 初回以外の毎月１日だったら，monthlyTempをyearlyTempに入れてから空にする．
            month = date.at(1).toInt();
            yearlyTemp.emplace_back(MontylySensorType(month, monthlyTemp));
            monthlyTemp.clear();
            monthlyTemp.emplace_back(DailySensorType(day, dailyTemp));
            dailyTemp.clear();
        }
        else
        {
            monthlyTemp.emplace_back(DailySensorType(day, dailyTemp));
            dailyTemp.clear();
        }
        if(month == 12 && day == 31)
        {
            year = date.at(0).toInt();
            data.push_back(YearlySensorType(year, yearlyTemp));
            yearlyTemp.clear();
        }
    }

    monthlyTemp.emplace_back(DailySensorType(day, dailyTemp));
    year = date.at(0).toInt();
    data.push_back(YearlySensorType(year, yearlyTemp));



    generateDataList();

}

QList<QString> DataManager::getDataList() const
{
    return dataList;
}

QList<QString> DataManager::getDataListAfter(int const index) const
{
    return dataList.mid(index, dataList.size() - index - 1);
}

void DataManager::generateDataList()
{
    dataList.clear();
    for(auto const& each_year : data)for(auto const& each_month : each_year.yearlyData)
    {
        dataList.append(QString::number(each_month.month) + "/" + QString::number(each_year.year));
    }
}

