#ifndef SERVICESLIST1_H
#define SERVICESLIST1_H

#include <QVariant>
#include <QList>

#include "Service.h"


class ServicesList1
{
public:
    ServicesList1();
    void addService(Service& newService);
    void removeService(int index);

public:
    Service getService(int index) const;

private:
    QList<Service> * servicesList;
};

#endif // SERVICESLIST1_H
