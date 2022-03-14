#include "mainwindow.h"

#include <QApplication>
#include<iostream>
#include<iostream>
#include<cstddef>
#include"myVector.h"
#include"myList.h"
#include"Itor.h"
#include "NewList.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "\nTask #1";
    unsigned int n=10, k=6;
    Vector<int> test(n);
    for(unsigned int i=0;i<n;i++){
        test.push(rand(),i);
    }
    cout << "\nRandom int vector (size " << test.size()<< "): ";
    test.print();
    test.remove(k);
    cout << "\nNew vector (delete element on " << k+1 << " position): ";
    test.print();

    cout << "\nRandom int list: ";
    List<int> testlist;
    testlist.push_back(1);
    testlist.push_back(2);
    testlist.push_back(3);
    testlist.put(4);
    testlist.push_back(5);
    testlist.push_front(6);
    testlist.put(7);
    List<int>::Link* temp=testlist.head;
    while (temp)
    {
       cout << temp->data << " ";
       temp = temp->suc;
    }

    cout << "\n";

    cout << "\nTask #6";
    NewList<int> ints;
    for(int i = 0; i<10;i++)
        ints.push_back(rand());
    cout << "\n";
    for (size_t i =0; i<ints.size();i++)
        cout << "ints[" << i << "]: " << ints[i] << "\n";
    cout << "\n";

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
