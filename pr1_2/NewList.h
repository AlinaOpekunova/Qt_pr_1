#ifndef NEWLIST_H
#define NEWLIST_H

#include <list>
using namespace std;

template<class T> class NewList{
private:
    list<T> ptr;
public:
    NewList(){};
    void push_back(T value){
        ptr.push_back(value);
    }
    int operator[] (int position){
        typename list <T> :: iterator it = ptr.begin();
        advance(it,position);
        return *it;
    };
    size_t size(){
        return ptr.size();
    }
};

#endif // NEWLIST_H
