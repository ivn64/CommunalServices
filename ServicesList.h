#ifndef SERVICESLIST1_H
#define SERVICESLIST1_H

#include <QVariant>
#include <QList>

#include "Service.h"


class ServicesList
{
public:
    ServicesList();
    void addService(Service * service);
    void removeService(int index);
    Service * getService(int index) const;

private:
    QList<Service *> * servicesList;
};

#endif // SERVICESLIST1_H
