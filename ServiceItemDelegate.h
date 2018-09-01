#ifndef SERVICEITEMDELEGATE_H
#define SERVICEITEMDELEGATE_H

#include <QStyledItemDelegate>

namespace Services {

class ServiceItemDelegate : public QStyledItemDelegate
{
public:
    explicit ServiceItemDelegate(QWidget *parent = nullptr);
    ~ServiceItemDelegate() override;

protected:
    void paint(QPainter * painter, const QStyleOptionViewItem &option, const QModelIndex & index ) const override;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const override;
};

}

#endif // SERVICEITEMDELEGATE_H
