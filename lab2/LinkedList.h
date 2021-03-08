//.b=40
//parte 1
// Carlos Gerardo Herrera Cortina
// A00821946

#include "node.h"

template <class T>
class LinkedList
{
public:
    //.d=4
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    int getSize();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    void deleteFirst();
    void deleteLast();
    void del(int pos);
    int deleteAll();
    T set(T data, int pos);
    T get(int pos);
    bool change(int pos1, int pos2); //.m
    void print();
    ///
    ///
    ///
    ///
    /// TAREA
    void reverse();
    friend bool operator==(LinkedList<T> L1, LinkedList<T> L2);
    void operator+=(T data);
    friend void operator+=(LinkedList<T>, LinkedList<T>);
    LinkedList(const LinkedList<T> &L1); //.m
    void operator=(LinkedList<T>);
    ///
    ///
    ///
    ///
    ///
    
private:
    node<T> *head; //.m
    int size;
    void borraTodo();
};