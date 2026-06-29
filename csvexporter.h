#ifndef CSVEXPORTER_H
#define CSVEXPORTER_H

#include <QString>

class QAbstractItemModel;

class CsvExporter
{
public:
    static bool exportToCsv(const QString& filePath, QAbstractItemModel* model);

private:
    static QString escapeCsvField(const QString& field);
};

#endif // CSVEXPORTER_H
