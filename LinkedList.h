#ifndef LINKED_LIST
#define LINKED_LIST

#include<iostream>

template<typename T> struct Node
{
    T data;
    Node* next;
};

template<typename T> class LinkedList
{
private:
    int length;
    Node<T>* head;
public:
    LinkedList();
    ~LinkedList();

    void push_back(T item);
    void insert(T item, int index);
    T getAtIndex(int index);
    T pop_head();

    int getLength();

    void print();

};

template<typename T> LinkedList<T>::LinkedList()
{
    this->length = 0;
    this->head = 0;
}

template<typename T> LinkedList<T>::~LinkedList()
{
    Node<T>* n = this->head;
    Node<T>* next = 0;

    while(n)
    {
        next = n->next;
        delete n;
        n = next;
    }

    this->head = 0;
}

template<typename T> T LinkedList<T>::getAtIndex(int index)
{
    if(index >= this->length)
        return 0;

    Node<T>* n = this->head;
    while(index > 0)
    {
        n = n->next;
        index--;
    }

    return n->data;
}

template<typename T> void LinkedList<T>::push_back(T item)
{
    Node<T>* nAdd = new Node<T>();
    nAdd->data = item;
    nAdd->next = 0;

    if(!this->head)
        this->head = nAdd;
    else
    {
        Node<T>* n = new Node<T>();
        n = this->head;
        while(n->next)
        {
            n = n->next;
        }
        n->next =  nAdd;
    }

    this->length++;
}

template<typename T> void LinkedList<T>::insert(T item, int index)
{
    if(index > this->length || index < 0)
        return;

    if(index == 0)
    {
        Node<T>* oldHead = this->head;
        Node<T>* nAdd = new Node<T>();
        nAdd->next = oldHead;
        nAdd->data = item;
        this->head = nAdd;
    }
    else
    {
        Node<T>* n = new Node<T>();
        n = this->head;
        while(index > 1){
            n = n->next;
            index--;
        }

        Node<T>* nAdd = new Node<T>();
        nAdd->data = item;
        nAdd->next = n->next;
        n->next = nAdd;
    }

    this->length++;

}

template<typename T> T LinkedList<T>::pop_head()
{
    if(this->length == 0)
        return 0;

    Node<T>* first = this->head;
    T firstData = first->data;

    Node<T>* newFirst = this->head->next;
    this->head = newFirst;

    delete first;
    this->length--;

    return firstData;
}

template<typename T> void LinkedList<T>::print()
{
    std::cout << "LL: " << "[" << this->length << "]";

    Node<T>* n = this->head;

    while(n != 0)
    {
        std::cout << n->data << "->";
        n = n->next;
    }
}

template<typename T> int LinkedList<T>::getLength() { return this->length; }

#endif
