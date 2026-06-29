#include "datagenerator.h"

#include <QRandomGenerator>
#include <QDateTime>
#include <QStringList>

deviceData DataGenerator::generate()
{
    deviceData data;
    data.deviceName = randomDeviceName();
    data.temperature = randomTemperature();
    data.humidity = randomHumidity();
    data.status = judgeStatus(data.temperature);
    data.createdTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    return data;
}

QString DataGenerator::randomDeviceName()
{
    QStringList deviceNames = {
        "温湿度传感器1",
        "温湿度传感器2",
        "温湿度传感器3",
        "烟雾传感器1",
        "设备A"
    };

    int index = QRandomGenerator::global()->bounded(deviceNames.size());
    return deviceNames[index];
}

double DataGenerator::randomTemperature()
{
    int temp = QRandomGenerator::global()->bounded(200,451);
    return temp/10.0;
}

int DataGenerator::randomHumidity()
{
    int hum = QRandomGenerator::global()->bounded(30, 91);
    return hum;
}

QString DataGenerator::judgeStatus(double temperature)
{
    if(temperature >= 38.0){
        return "报警";
    }
    return "正常";
}
