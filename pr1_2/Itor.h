#ifndef ITOR_H
#define ITOR_H
#include"myVector.h"
#include"myList.h"
template <class T> class Itor {
public:
    virtual T* first() = 0;// Указатель на первый элемент
    virtual T* next() = 0;// Указатель на следующий элемент
};

template <class T> class Vector_itor: public Itor<T> {
    Vector<T>& v;
    size_t index;
public:
    Vector_itor (Vector <T>& vv);
    T* first(){
        return *v[0];
    };
    T* next(T* i){
        return *v[i++];
    };
};

template <class T> class List_itor: public Itor<T> {
public:
    List_itor(List<T>&);
    T* first();
    T* next();
};

#endif // ITOR_H
