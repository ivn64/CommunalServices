#ifndef SERVICESLIST_H
#define SERVICESLIST_H

#include <QAbstractTableModel>
#include <QList>
#include <QModelIndex>
#include "Service.h"

class ServicesList : public QAbstractTableModel
{
public:
    ServicesList(QObject *parent);
    void addService(Service& newService);
    void removeService(const QModelIndex & index);
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

private:
    QVariant getData(int num, int position) const;

private:
    QList<Service> * servicesList;
};

#endif // SERVICESLIST_H
