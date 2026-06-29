#include "databasemanager.h"
#include <QDebug>
#include<QSqlQuery>
#include <QSqlError>
#include <QDateTime>

DatabaseManager::DatabaseManager() {

}

bool DatabaseManager::initDatabase()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("device.db");
    if(!db.open()){
        qDebug()<<"数据库创建失败:"<<db.lastError().text();
        return false;
    }
    qDebug()<<"数据库创建成功!";
    return createTables();
}

bool DatabaseManager::insertData(const deviceData &data)
{
    deviceData saveData = data;

    if (saveData.temperature >= 38.0) {
        saveData.status = "报警";
    }

    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO device_data
        (device_name, temperature, humidity, status, created_time)
        VALUES
        (:device_name, :temperature, :humidity, :status, :created_time)
    )");

    query.bindValue(":device_name", saveData.deviceName);
    query.bindValue(":temperature", saveData.temperature);
    query.bindValue(":humidity", saveData.humidity);
    query.bindValue(":status", saveData.status);
    query.bindValue(":created_time", saveData.createdTime);

    if (!query.exec()) {
        qDebug() << "插入数据失败：" << query.lastError().text();
        return false;
    }

    qDebug() << "插入数据成功：" << saveData.deviceName;

    if (saveData.temperature >= 38.0) {
        QString alarmMessage = "温度过高，当前温度：" + QString::number(saveData.temperature, 'f', 1) + " ℃";

        insertAlarmRecord(saveData, "温度报警", alarmMessage);
    }

    return true;
}

QSqlTableModel *DatabaseManager::getDeviceDataModel(QObject *parent)
{
    QSqlTableModel *model = new QSqlTableModel(parent,db);
    model->setTable("device_data");
    model->select();

    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"设备名");
    model->setHeaderData(2,Qt::Horizontal,"温度");
    model->setHeaderData(3,Qt::Horizontal,"湿度");
    model->setHeaderData(4,Qt::Horizontal,"状态");
    model->setHeaderData(5,Qt::Horizontal,"时间");
    return model;
}

bool DatabaseManager::deleteData(int id)
{
    QSqlQuery query;
    QString str = R"(
        delete from device_data where id = :id
    )";
    query.prepare(str);
    query.bindValue(":id",id);
    if(!query.exec()){
        qDebug()<<"删除数据失败:"<<query.lastError().text();
        return false;
    }
    qDebug()<<"删除数据成功,ID: "<<id;
    return true;
}

bool DatabaseManager::updateData(const deviceData &data)
{
    deviceData saveData = data;

    if (saveData.temperature >= 38.0) {
        saveData.status = "报警";
    }

    QSqlQuery query;

    query.prepare(R"(
        UPDATE device_data
        SET device_name = :device_name,
            temperature = :temperature,
            humidity = :humidity,
            status = :status
        WHERE id = :id
    )");

    query.bindValue(":device_name", saveData.deviceName);
    query.bindValue(":temperature", saveData.temperature);
    query.bindValue(":humidity", saveData.humidity);
    query.bindValue(":status", saveData.status);
    query.bindValue(":id", saveData.id);

    if (!query.exec()) {
        qDebug() << "修改数据失败：" << query.lastError().text();
        return false;
    }

    qDebug() << "修改数据成功，ID =" << saveData.id;

    if (saveData.temperature >= 38.0) {
        QString alarmMessage = "修改数据触发温度报警，当前温度：" + QString::number(saveData.temperature, 'f', 1) + " ℃";

        insertAlarmRecord(saveData, "温度报警", alarmMessage);
    }

    return true;
}

bool DatabaseManager::createTables()
{
    QSqlQuery sql;
    QString createDeviceDataTable = R"(
        CREATE TABLE IF NOT EXISTS device_data(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            device_name TEXT NOT NULL,
            temperature REAL,
            humidity INTEGER,
            status TEXT,
            created_time TEXT
        )
    )";

    if(!sql.exec(createDeviceDataTable)){
        qDebug()<<"设备数据表创建失败:"<<sql.lastError().text();
        return false;
    }
    qDebug()<<"设备数据表创建成功!";

    QString createAlarmRecordTable = R"(
        CREATE TABLE IF NOT EXISTS alarm_record(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            device_name TEXT NOT NULL,
            temperature REAL,
            alarm_type TEXT,
            alarm_message TEXT,
            created_time TEXT
        )
    )";

    if(!sql.exec(createAlarmRecordTable)){
        qDebug()<<"报警记录表创建失败:"<<sql.lastError().text();
        return false;
    }
    qDebug()<<"报警记录表创建成功!";

    return true;
}

bool DatabaseManager::insertAlarmRecord(const deviceData &data, const QString &alarmType, const QString &alarmMessage)
{
    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO alarm_record
        (device_name, temperature, alarm_type, alarm_message, created_time)
        VALUES
        (:device_name, :temperature, :alarm_type, :alarm_message, :created_time)
    )");

    QString createdTime = data.createdTime;
    if (createdTime.isEmpty()) {
        createdTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    }

    query.bindValue(":device_name", data.deviceName);
    query.bindValue(":temperature", data.temperature);
    query.bindValue(":alarm_type", alarmType);
    query.bindValue(":alarm_message", alarmMessage);
    query.bindValue(":created_time", createdTime);

    if (!query.exec()) {
        qDebug() << "报警记录写入失败：" << query.lastError().text();
        return false;
    }

    qDebug() << "报警记录写入成功：" << data.deviceName << alarmMessage;
    return true;
}


