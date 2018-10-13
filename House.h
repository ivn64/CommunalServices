#ifndef HOUSE_H
#define HOUSE_H

#include <QString>
#include <QDataStream>
#include <QList>

#include "DataList.h"
#include "ProfitsDate.h"

class House
{
public:
    House();
    House(const House * obj);

    QString getName();
    void setName(QString value);
    QString getAdress();
    void setAdress(QString value);
    float getArea();
    void setArea(float value);
    int getNumberOfPeoples();
    void setNumberOfPeoples(int value);
    bool getIsPrivate();
    void setIsPrivate(bool value);

    friend QDataStream &operator<<(QDataStream &d, House * u);
    friend QDataStream &operator>>(QDataStream &d, House * u);

private:
    QString name;
    QString adress;
    float area;
    int numberOfPeoples;
    bool isPrivate;
    QList<ProfitsDate> profits;

};

inline QDataStream& operator<<( QDataStream& d, House * u )
{
    d << u->name << u->adress << u->area << u->numberOfPeoples << u->isPrivate;
    for (auto item : u->profits)
        d << &item;
    return d;
}

inline QDataStream& operator>>( QDataStream& d, House * u )
{
    d >> u->name >> u->adress >> u->area >> u->numberOfPeoples >> u->isPrivate;
    for (auto item : u->profits)
        d >> &item;
    return d;
}

#endif // HOUSE_H
