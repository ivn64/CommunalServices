#ifndef PROFITSDATE_H
#define PROFITSDATE_H

#include <QList>
#include <QDataStream>

#include "Profit.h"

class ProfitsDate
{
public:
    ProfitsDate();

    int getYear() const;
    void setYear(int value);
    int getMonth() const;
    void setMonth(int value);

    void addProfit(const Profit & profit);

    friend QDataStream &operator<<(QDataStream &d, ProfitsDate * u);
    friend QDataStream &operator>>(QDataStream &d, ProfitsDate * u);

private:
    int year;
    int month;
    QList<Profit> profits;

};

inline QDataStream& operator<<( QDataStream& d, ProfitsDate * u )
{
    d << u->year << u->month;
    for (auto item : u->profits)
        d << &item;
    return d;
}

inline QDataStream& operator>>( QDataStream& d, ProfitsDate * u )
{
    d >> u->year >> u->month;
    for (auto item : u->profits)
        d >> &item;
    return d;
}

#endif // PROFITSDATE_H
