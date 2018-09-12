#ifndef HOUSE_H
#define HOUSE_H

#include <QString>
#include <QDataStream>

struct House
{
    QString name = "Новый объект";
    QString adress = "Адрес";
    float area = 0;
    int numberOfPeoples = 0;
    bool isPrivate = false;

    friend QDataStream &operator<<(QDataStream &d, House * u);
    friend QDataStream &operator>>(QDataStream &d, House * u);

    House()
    {
    }

    House(const House * obj)
    {
        name = obj->name;
        adress = obj->adress;
        area = obj->area;
        numberOfPeoples = obj->numberOfPeoples;
        isPrivate = obj->isPrivate;
    }
};

inline QDataStream& operator<<( QDataStream& d, House * u )
{
    d << u->name << u->adress << u->area << u->numberOfPeoples << u->isPrivate;
    return d;
}

inline QDataStream& operator>>( QDataStream& d, House * u )
{
    d >> u->name >> u->adress >> u->area >> u->numberOfPeoples >> u->isPrivate;
    return d;
}

#endif // HOUSE_H
