#include "ServicesList1.h"

ServicesList1::ServicesList1()
{
    servicesList = new QList<Service>();
}

void ServicesList1::addService(Service &newService)
{
    servicesList->append(newService);
}

void ServicesList1::removeService(int index)
{
    servicesList->removeAt(index);
}

Service ServicesList1::getService(int index) const
{
    return servicesList->at(index);
}
