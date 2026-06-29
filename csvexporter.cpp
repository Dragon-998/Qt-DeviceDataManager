#include "csvexporter.h"

#include <QAbstractItemModel>
#include <QFile>
#include <QTextStream>
#include <QModelIndex>
#include <QStringList>
#include <QStringConverter>

bool CsvExporter::exportToCsv(const QString &filePath, QAbstractItemModel *model)
{
    if(filePath.isEmpty() || !model){
        return false;
    }

    QFile file(filePath);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    out.setEncoding(QStringConverter::Utf8);
#else
    out.setCodec("UTF-8");
#endif

    out << QChar(0xFEFF);

    int rowCount = model->rowCount();
    int colCount = model->columnCount();

    QStringList headerList;
    for(int col=0; col<colCount; ++col){
        QString header = model->headerData(col,Qt::Horizontal).toString();
        headerList << escapeCsvField(header);
    }
    out << headerList.join(",") << "\r\n";

    for(int row=0; row<rowCount; ++row){
        QStringList rowList;
        for(int col=0; col<colCount; col++){
            QModelIndex index = model->index(row,col);
            QString value = model->data(index).toString();
            rowList << escapeCsvField(value);
        }
        out << rowList.join(',') << "\r\n";
    }

    file.close();
    return true;
}

QString CsvExporter::escapeCsvField(const QString &field)
{
    QString result = field;

    result.replace("\"","\"\"");
    return "\"" + result + "\"";
}
