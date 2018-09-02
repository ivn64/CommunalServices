#ifndef SERVICES_H
#define SERVICES_H

#include <QString>

struct Service
{
    QString name = "Новая услуга";
    bool isMeter = true;
    QString unit = "м2";
    float price = 0;

    friend QDataStream &operator<<(QDataStream &d, Service * u);
};

inline QDataStream& operator<<( QDataStream& d, Service * u )
{
    d << u->name << u->isMeter << u->unit << u->price;
    return d;
}

#endif // SERVICES_H
