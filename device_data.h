#ifndef DEVICE_DATA_H
#define DEVICE_DATA_H
#include <QString>

struct deviceData
{
    int id = -1;
    QString deviceName;
    double temperature = 0.0;
    int humidity = 0;
    QString status;
    QString createdTime;
};

#endif // DEVICE_DATA_H
