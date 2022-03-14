#ifndef LOGOPERATION_H
#define LOGOPERATION_H
#include<QString>
#include <vector>
#include <bitset>
using namespace std;

template <class T> class And {
public:
    vector<T> operator()(vector<T> x, vector<T> y) {
        unsigned int size = 0;
        if (x.size() < y.size()){
            size = x.size();
        } else {
            size = y.size();
        }
        vector<T> result(size);
        int index = 0;
        for (unsigned int i=0; i < size; i++){
            result[index] = (x[i] & y[i]);
            index++;
        }
        return result;
    }
};

template <class T> class Or {
public:
    vector<T> operator()(vector<T> x, vector<T> y) {
        unsigned int size = 0;
        if (x.size() > y.size())
            size = x.size();
        else
            size = y.size();
        vector<T> result(size);
        int index = 0;
        for (unsigned int i=0; i < size; i++){
            if (i < x.size() && i < y.size())
                result[index++] = (x[i] | y[i]);
            else if (i >= x.size() && i < y.size())
                result[index++] = y[i];
            else if (i < x.size() && i >= y.size())
                result[index++] = x[i];
        }
        return result;

    }
};

template <class T> class Xor {
public:
    vector<T> operator()(vector<T> x, vector<T> y) {
        unsigned int size = 0;
        if (x.size() > y.size())
            size = x.size();
        else
            size = y.size();
        vector<T> result(size);
        int index = 0;
        for (unsigned int i=0; i < size; i++){
            if (i < x.size() && i < y.size())
                result[index++] = (x[i] ^ y[i]);
            else if (i >= x.size() && i < y.size())
                result[index++] = y[i];
            else if (i < x.size() && i >= y.size())
                result[index++] = x[i];
        }
        return result;
    }
};

template <class T> class Not {
    public:
    vector<T> operator()(vector<T> x) {
        vector<T> result(x.size());
        unsigned int index = 0;
        for (unsigned int i=0; i < x.size(); i++){
            result[index++] = (~x[i]);
        }
        return result;
    }
};


class IntPrinter
{
public:
    QString operator()(std::vector<int> &numbers);
};

class CharPrinter
{
public:
    QString operator()(std::vector<char> &chars);
};

class BitsetPrinter
{
public:
    QString operator()(std::vector<bitset<67>> &chars);
};

#endif // LOGOPERATION_H
