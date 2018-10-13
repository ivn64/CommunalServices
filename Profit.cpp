#include "Profit.h"

Profit::Profit()
{

}

QString Profit::getService() const
{
    return service;
}

void Profit::setService(const QString value)
{
    service = value;
}

float Profit::getIndications() const
{
    return indications;
}

void Profit::setIndications(float value)
{
    indications = value;
}

QString Profit::getUnit() const
{
    return unit;
}

void Profit::setUnit(const QString value)
{
    unit = value;
}

float Profit::getCost() const
{
    return cost;
}

void Profit::setCost(float value)
{
    cost = value;
}

float Profit::getAccruals() const
{
    return accruals;
}

void Profit::setAccruals(float value)
{
    accruals = value;
}
