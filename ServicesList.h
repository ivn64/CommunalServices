#ifndef SERVICESLIST1_H
#define SERVICESLIST1_H

#include <QVariant>
#include <QList>

#include "Service.h"

template <class T>
class ServicesList : QDataStream
{
public:
    ServicesList();
    ~ServicesList();
    void addService(Service * service);
    void removeService(int index);
    Service * getService(int index) const;
    void save();

private:
    QList<T> servicesList;
};

template <class T>
ServicesList<T>::ServicesList()
{

}

template <class T>
ServicesList<T>::~ServicesList()
{
    for(auto item : servicesList)
        delete item;
}

template <class T>
void ServicesList<T>::addService(Service * service)
{
    servicesList.append(service);
}

template <class T>
void ServicesList<T>::removeService(int index)
{
    if (index > -1 && index < servicesList.count())
    {
        delete servicesList.at(index);
        servicesList.removeAt(index);
    }
}

template <class T>
Service * ServicesList<T>::getService(int index) const
{
    if (index > -1 && index < servicesList.count())
    {
        return servicesList.at(index);
    }
    return nullptr;
}

template <class T>
void ServicesList<T>::save()
{
    QFile file( "service.txt" );
    QDataStream stream( &file );

    file.open( QIODevice::WriteOnly );
    stream << servicesList.at(0);
    file.close();
}

#endif // SERVICESLIST1_H
