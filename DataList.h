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
    void removeAllItems();
    void save(QString fileName);
    void load(QString fileName);
};

template <class T>
DataList<T>::DataList()
{
}

template <class T>
DataList<T>::~DataList()
{
    for(int i = 0; i < this->size(); i++)
        delete this->at(i);
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
void DataList<T>::removeAllItems()
{
    for(int i = 0; i < this->size(); i++)
        delete this->at(i);
    this->clear();
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

template<typename T>
struct remove_pointer
{
    typedef T type;
};

template<typename T>
struct remove_pointer<T*>
{
    typedef T type;
};

template <class T>
void DataList<T>::load(QString fileName)
{
    QFile file(fileName);
    QDataStream stream(&file);
    if (file.open(QIODevice::ReadOnly))
    {
        int size;
        stream >> size;
        for (int i = 0; i < size; i++)
        {
            typedef typename remove_pointer<T>::type type;
            T addingT = new type();
            this->append(addingT);
            stream >> this->at(i);
        }
    }
    file.close();
}

#endif // SERVICESLIST1_H
