#include "ServiceItemDelegate.h"

#include <QRect>
#include <QPainter>

#include "ServicesDialog.h"

namespace Services {

ServiceItemDelegate::ServiceItemDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{
}

ServiceItemDelegate::~ServiceItemDelegate() = default;

void ServiceItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItemV4 optionV4 = option;
    initStyleOption(&optionV4, index);

    QRect fillRect = option.rect.adjusted(0, 0, 0, 0);
    painter->fillRect(fillRect, "red");

    QPen textColor = QColor("black");
    painter->setPen(textColor);
    painter->setFont(QFont("Verdana", 20));
    QFontMetrics fontMetrics(painter->font());
    QString themeStyle = index.data(Services::Name).toString();
    QRect textRect = option.rect.adjusted(0, 0, 50, 50);
    QString elidedText = fontMetrics.elidedText(themeStyle, Qt::ElideRight, 100);
    painter->drawText(textRect.left(), textRect.top(), textRect.width(), textRect.height(), Qt::AlignLeft, elidedText, &textRect);
    if(option.state & QStyle::State_Selected)
    {
        painter->fillRect(fillRect, "green");
    }
}

QSize ServiceItemDelegate::sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    QStyleOptionViewItemV4 optionV4 = option;
    initStyleOption(&optionV4, index);

    return QSize(100, 100);
}

}
