#include "alarmhighlightdelegate.h"

#include <QPainter>
#include <QStyleOptionViewItem>
#include <QAbstractItemModel>
#include <QBrush>
#include <QColor>
#include <QStyle>

AlarmHighlightDelegate::AlarmHighlightDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void AlarmHighlightDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);

    double temperature = index.model()->data(index.model()->index(index.row(), 2)).toDouble();
    int humidity = index.model()->data(index.model()->index(index.row(), 3)).toInt();
    QString status = index.model()->data(index.model()->index(index.row(), 4)).toString().trimmed();

    bool isAlarm = false;

    if (temperature >= 38.0) {
        isAlarm = true;
    }

    if (humidity >= 80) {
        isAlarm = true;
    }

    if (status.contains("报警") || status.contains("异常")) {
        isAlarm = true;
    }

    if (isAlarm) {
        painter->save();

        // 先手动画背景，比 opt.backgroundBrush 更稳
        if (!(opt.state & QStyle::State_Selected)) {
            painter->fillRect(opt.rect, QColor(255, 220, 220));
        }

        opt.palette.setColor(QPalette::Text, QColor(180, 0, 0));
        opt.font.setBold(true);

        painter->restore();
    }

    QStyledItemDelegate::paint(painter, opt, index);
}

