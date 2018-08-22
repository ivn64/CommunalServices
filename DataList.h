#ifndef DATALIST_H
#define DATALIST_H

#include <QList>

template <class T>
class DataList : public QList<T>
{
public:
    DataList();
    ~DataList();
};

template <class T>
DataList<T>::DataList()
{
}

template <class T>
DataList<T>::~DataList()
{
    for (int i = 0; i < this->size(); i++)
        delete this[i];
}

#endif // DATALIST_H
