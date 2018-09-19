#ifndef PROFITTABLE_H
#define PROFITTABLE_H

#include <QString>

class ProfitTable
{
public:
    ProfitTable();

    int getYear() const;
    void setYear(int value);
    QString getMonth() const;
    void setMonth(const QString value);
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

private:
    int year;
    QString month;
    QString service;
    float indications;
    QString unit;
    float cost;
    float accruals;

};

#endif // PROFITTABLE_H
