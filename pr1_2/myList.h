#ifndef MYLIST_H
#define MYLIST_H

template <class T> class List {
public:
    struct Link {
        Link* pre; // ссылка на предыдущий элемент
        Link* suc; // ссылка на следующий элемент
        T data;
        Link():suc(nullptr),pre(nullptr){};
        Link(T d):data(d),suc(nullptr),pre(nullptr){};
    };
    Link* head = nullptr;
    Link* tail = nullptr;

    Link* getHead(){
        return head;
    };

    Link* getTail(){
        return tail;
    };

    void put(T value)
    {// Вставить перед текущим элементом
        Link* current = new Link(value);
        current->pre = tail->pre;
        tail -> pre -> suc = current;
        tail -> pre = current;
        current -> suc = tail;
    };

    T get(Link *node)
    { // Получить текущий элемент
        return node->data;
    };

    void push_back(T value)
    {
        Link* current = new Link(value);
        if (head == nullptr)
        {
            head = current;
        }
        else
        {
            tail -> suc = current;
            current -> pre = tail;
        }
        tail = current;
    }

    void push_front(T value)
    {
        Link* current = new Link(value);
        if (head == nullptr)
        {
            head = current;
            tail = current;
        }
        else
        {
            head -> pre = current;
            current -> suc = head;
            head = current;
        }
    };
};

#endif // MYLIST_H
