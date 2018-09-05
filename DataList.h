#ifndef SERVICESLIST1_H
#define SERVICESLIST1_H

#include <QList>

template <class T>
class DataList : public QList<T>
{
public:
    DataList();
    ~DataList();
    void removeItem(int index);
    void save(QString fileName);
};

template <class T>
DataList<T>::DataList()
{
}

template <class T>
DataList<T>::~DataList()
{
    for(auto item : this)
        delete item;
}

template <class T>
void DataList<T>::removeItem(int index)
{
    if (index > -1 && index < this->count())
    {
        delete this->at(index);
        this->removeAt(index);
    }
}

template <class T>
void DataList<T>::save(QString fileName)
{
    QFile file(fileName);
    QDataStream stream(&file);
    if (file.open(QIODevice::WriteOnly))
    {
        stream << this->size();
        for (int i = 0; i < this->size(); i++)
            stream << this->at(i);
    }
    file.close();
}

#endif // SERVICESLIST1_H
