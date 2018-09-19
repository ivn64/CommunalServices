#include "Service.h"

Service::Service()
{
    name = "Новая услуга";
    isMeter = true;
    unit = "м2";
    price = 0;
}

Service::Service(const Service * obj)
{
    name = obj->name;
    isMeter = obj->isMeter;
    unit = obj->unit;
    price = obj->price;
}

QString Service::getName()
{
    return name;
}

void Service::setName(QString value)
{
    name = value;
}

bool Service::getIsMeter()
{
    return isMeter;
}

void Service::setIsMeter(bool value)
{
    isMeter = value;
}

QString Service::getUnit()
{
    return unit;
}

void Service::setUnit(QString value)
{
    unit = value;
}

float Service::getPrice()
{
    return price;
}

void Service::setPrice(float value)
{
    price = value;
}
