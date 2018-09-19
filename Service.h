#ifndef SERVICES_H
#define SERVICES_H

#include <QString>
#include <QDataStream>

class Service
{
public:
    Service();
    Service(const Service * obj);

    QString getName();
    void setName(QString value);
    bool getIsMeter();
    void setIsMeter(bool value);
    QString getUnit();
    void setUnit(QString value);
    float getPrice();
    void setPrice(float value);

    friend QDataStream &operator<<(QDataStream &d, Service * u);
    friend QDataStream &operator>>(QDataStream &d, Service * u);

private:
    QString name;
    bool isMeter;
    QString unit;
    float price;
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
