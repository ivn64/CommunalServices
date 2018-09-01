#include "ServicesList.h"

ServicesList::ServicesList()
{

}

ServicesList::~ServicesList()
{
    for(auto item : servicesList)
        delete item;
}

void ServicesList::addService(Service * service)
{
    servicesList.append(service);
}

void ServicesList::removeService(int index)
{
    if (index > -1 && index < servicesList.count())
    {
        delete servicesList.at(index);
        servicesList.removeAt(index);
    }
}

Service * ServicesList::getService(int index) const
{
    if (index > -1 && index < servicesList.count())
    {
        return servicesList.at(index);
    }
    return nullptr;
}
