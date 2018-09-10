#ifndef SERVICES_H
#define SERVICES_H

#include <QString>
#include <QDataStream>

struct Service
{
    QString name = "Новая услуга";
    bool isMeter = true;
    QString unit = "м2";
    float price = 0;

    friend QDataStream &operator<<(QDataStream &d, Service * u);
    friend QDataStream &operator>>(QDataStream &d, Service * u);

    Service()
    {
    }

    Service(const Service * obj)
    {
        name = obj->name;
        isMeter = obj->isMeter;
        unit = obj->unit;
        price = obj->price;
    }
};

inline QDataStream& operator<<( QDataStream& d, Service * u )
{
    d << u->name << u->isMeter << u->unit << u->price;
    return d;
}

inline QDataStream& operator>>( QDataStream& d, Service * u )
{
    d >> u->name >> u->isMeter >> u->unit >> u->price;
    return d;
}

#endif // SERVICES_H
