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

QList<Profit> ProfitsDate::getProfits() const
{
    return m_profits;
}

void ProfitsDate::addProfit(const Profit & profit)
{
    m_profits.append(profit);
}

void ProfitsDate::addProfits(QList<Profit> profits)
{
    m_profits.append(profits);
}
