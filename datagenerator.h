#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include "device_data.h"

class DataGenerator
{
public:
    static deviceData generate();

private:
    static QString randomDeviceName();
    static double randomTemperature();
    static int randomHumidity();
    static QString judgeStatus(double temperature);
};

#endif // DATAGENERATOR_H
