#ifndef ALARMHIGHLIGHTDELEGATE_H
#define ALARMHIGHLIGHTDELEGATE_H

#include <QStyledItemDelegate>

class AlarmHighlightDelegate : public QStyledItemDelegate
{
public:
    explicit AlarmHighlightDelegate(QObject* parent = nullptr);

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};

#endif // ALARMHIGHLIGHTDELEGATE_H
