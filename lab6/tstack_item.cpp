#include <iostream>
#include <memory>
#include "tstack_item.h"

template <class T>
TStackItem<T>::TStackItem(const T &val, TStackItem<T> *item)
{
    value = new T(val);
    next = item;
}

template <class T>
void TStackItem<T>::Push(const T &val)
{
    *value = val;
}

template <class T>
T &TStackItem<T>::Pop() const
{
    return *value;
}

template <class T>
void TStackItem<T>::SetNext(TStackItem<T> *item)
{
    next = item;
}

template <class T>
TStackItem<T> &TStackItem<T>::GetNext() const
{
    return *next;
}

template <class T>
TStackItem<T>::~TStackItem()
{
    delete value;
}

template class
TStackItem<void *>;