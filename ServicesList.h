#ifndef SERVICESLIST1_H
#define SERVICESLIST1_H

#include <QList>

template <class T>
class ServicesList : QDataStream
{
public:
    ServicesList();
    ~ServicesList();
    void addService(T service);
    void removeService(int index);
    T getService(int index) const;
    void save(QString fileName);

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
void ServicesList<T>::addService(T service)
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
T ServicesList<T>::getService(int index) const
{
    if (index > -1 && index < servicesList.count())
    {
        return servicesList.at(index);
    }
    return nullptr;
}

template <class T>
void ServicesList<T>::save(QString fileName)
{
    QFile file(fileName);
    QDataStream stream(&file);
    if (file.open(QIODevice::WriteOnly))
    {
        stream << servicesList.size();
        for (auto item : servicesList)
            stream << item;
    }
    file.close();
}

#endif // SERVICESLIST1_H
