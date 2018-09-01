#include "ServicesList.h"

ServicesList::ServicesList(QObject *parent) : QAbstractTableModel(parent)
{
    servicesList = new QList<Service> ();
    Service test;
    servicesList->append(test);
}

void ServicesList::addService(Service& newService)
{
    beginInsertRows(QModelIndex(), servicesList->size(), servicesList->size());
    servicesList->append(newService);
    endInsertRows();
}

void ServicesList::removeService(const QModelIndex & index)
{
    beginRemoveRows(QModelIndex(), index.row(), index.row());
    servicesList->removeAt(index.row());
    endRemoveRows();
}

 int ServicesList::columnCount(const QModelIndex & parent) const
{
    return 4;
}

int ServicesList::rowCount(const QModelIndex& parent) const
{
    return servicesList->size();
}

QVariant ServicesList::data(const QModelIndex& index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole)
        return getData(index.row(), index.column());
    return QVariant();
}

QVariant ServicesList::getData(int num, int position) const
{
    switch (position) {
        case 0:
            return QVariant(servicesList->at(num).name);
        case 1:
            return QVariant(servicesList->at(num).isMeter);
        case 2:
            return QVariant(servicesList->at(num).price);
        case 3:
            return QVariant(servicesList->at(num).unit);
        default:
            return QVariant();
    }
}
