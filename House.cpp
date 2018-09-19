#include "House.h"

House::House()
{
    name = "Новый объект";
    adress = "Адрес";
    area = 0;
    numberOfPeoples = 0;
    isPrivate = false;
}

House::House(const House * obj)
{
    name = obj->name;
    adress = obj->adress;
    area = obj->area;
    numberOfPeoples = obj->numberOfPeoples;
    isPrivate = obj->isPrivate;
}

QString House::getName()
{
    return name;
}

void House::setName(QString value)
{
    name = value;
}

QString House::getAdress()
{
    return adress;
}

void House::setAdress(QString value)
{
    adress = value;
}

float House::getArea()
{
    return area;
}

void House::setArea(float value)
{
    area = value;
}

int House::getNumberOfPeoples()
{
    return numberOfPeoples;
}

void House::setNumberOfPeoples(int value)
{
    numberOfPeoples = value;
}

bool House::getIsPrivate()
{
    return isPrivate;
}

void House::setIsPrivate(bool value)
{
    isPrivate = value;
}
