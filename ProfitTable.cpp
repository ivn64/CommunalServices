#include "ProfitTable.h"

ProfitTable::ProfitTable()
{

}

int ProfitTable::getYear() const
{
    return year;
}

void ProfitTable::setYear(int value)
{
    year = value;
}

int ProfitTable::getMonth() const
{
    return month;
}

void ProfitTable::setMonth(const int value)
{
    month = value;
}

QString ProfitTable::getService() const
{
    return service;
}

void ProfitTable::setService(const QString value)
{
    service = value;
}

float ProfitTable::getIndications() const
{
    return indications;
}

void ProfitTable::setIndications(float value)
{
    indications = value;
}

QString ProfitTable::getUnit() const
{
    return unit;
}

void ProfitTable::setUnit(const QString value)
{
    unit = value;
}

float ProfitTable::getCost() const
{
    return cost;
}

void ProfitTable::setCost(float value)
{
    cost = value;
}

float ProfitTable::getAccruals() const
{
    return accruals;
}

void ProfitTable::setAccruals(float value)
{
    accruals = value;
}
