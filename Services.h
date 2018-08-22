#ifndef SERVICES_H
#define SERVICES_H

#include <QString>

struct Services
{
    QString name = "Новая услуга";
    bool isMeter = true;
    QString unit = "м2";
    float price = 0;

/*private:
	Services()
	{
		name = "Новая услуга";
		isMeter = true;
		unit = "м2";
		price = 0;
    }*/
};

#endif // SERVICES_H
