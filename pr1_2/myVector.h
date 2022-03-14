#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <cstddef>
#include<iostream>

using namespace std;

template <class T> class Vector{
public:
    explicit Vector(size_t n)
    {// конструктор создает вектор указанного размера
        sizeVector = n;
        data = new T[n];
    };

    T& operator[](size_t index)
    {// получение элемента по индексу
        return data[index];
    };

    size_t size()
    {// получение размера вектора
        return sizeVector;
    };

    void push(int value, int index)
    {// добавление элемента по индексу
        data[index] = value;
    }

    void print()
    {// вывод вектора на экран
        for (size_t i = 0; i < sizeVector; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void remove(size_t index)
    {// удаление элемента по индексу
        for (size_t i = index + 1; i < sizeVector; ++i) {
            data[i - 1] = data[i];
        }
        --sizeVector;
    }

    ~Vector()
    {// деструктор
        delete [] data;
    };
private:
    T* data;
    size_t sizeVector;
};
#endif // MYVECTOR_H
