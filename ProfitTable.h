#ifndef PROFITTABLE_H
#define PROFITTABLE_H

#include <QString>
#include <QDataStream>

class ProfitTable
{
public:
    ProfitTable();

    int getYear() const;
    void setYear(int value);
    int getMonth() const;
    void setMonth(const int value);
    QString getService() const;
    void setService(const QString value);
    float getIndications() const;
    void setIndications(float value);
    QString getUnit() const;
    void setUnit(const QString value);
    float getCost() const;
    void setCost(float value);
    float getAccruals() const;
    void setAccruals(float value);

    friend QDataStream &operator<<(QDataStream &d, ProfitTable * u);
    friend QDataStream &operator>>(QDataStream &d, ProfitTable * u);

private:
    int year;
    int month;
    QString service;
    float indications;
    QString unit;
    float cost;
    float accruals;

};

inline QDataStream& operator<<( QDataStream& d, ProfitTable * u )
{
    d << u->year << u->month << u->service << u->indications << u->unit << u->cost << u->accruals;
    return d;
}

inline QDataStream& operator>>( QDataStream& d, ProfitTable * u )
{
    d >> u->year >> u->month >> u->service >> u->indications >> u->unit >> u->cost >> u->accruals;
    return d;
}

#endif // PROFITTABLE_H
