#include "ProfitsDate.h"

ProfitsDate::ProfitsDate()
{

}

int ProfitsDate::getYear() const
{
    return year;
}

void ProfitsDate::setYear(int value)
{
    year = value;
}

int ProfitsDate::getMonth() const
{
    return month;
}

void ProfitsDate::setMonth(int value)
{
    month = value;
}
