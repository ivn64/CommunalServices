#ifndef PROFIT_H
#define PROFIT_H

#include <QString>
#include <QDataStream>

class Profit
{
public:
    Profit();

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

    friend QDataStream &operator<<(QDataStream &d, Profit * u);
    friend QDataStream &operator>>(QDataStream &d, Profit * u);

private:
    QString service;
    float indications;
    QString unit;
    float cost;
    float accruals;

};

inline QDataStream& operator<<( QDataStream& d, Profit * u )
{
    d << u->service << u->indications << u->unit << u->cost << u->accruals;
    return d;
}

inline QDataStream& operator>>( QDataStream& d, Profit * u )
{
    d >> u->service >> u->indications >> u->unit >> u->cost >> u->accruals;
    return d;
}

#endif // PROFIT_H
