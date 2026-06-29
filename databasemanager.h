#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "device_data.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlTableModel>

class DatabaseManager
{
public:
    DatabaseManager();
    //初始化数据库
    bool initDatabase();
    //插入数据
    bool insertData(const deviceData& data);
    //返回数据
    QSqlTableModel* getDeviceDataModel(QObject* parent = nullptr);
    //删除数据
    bool deleteData(int id);
    //修改数据
    bool updateData(const deviceData& data);

private:
    //创建表
    bool createTables();

    bool insertAlarmRecord(const deviceData& data,const QString& alarmType,const QString& alarmMessage);


private:
    QSqlDatabase db;

};

#endif // DATABASEMANAGER_H
