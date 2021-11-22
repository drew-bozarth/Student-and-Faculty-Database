/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - ListInterface.h */

/*
This is the ListInterface template class that is being used to create a DoublyLinked List using LinkedList.h
*/

#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//includes the DoublyLinkedList template Class
#include "LinkedList.h"
//standard namespace libaray in C++
using namespace std;

/*
Template Class: ListInterface
*/
template <class T>
class ListInterface{
  public:
    ListInterface(){}; //default constructor
    virtual ~ListInterface(){}; //destructor

    virtual void append(T item){};
    virtual void prepend(T item){};
    virtual void insertAfter(ListNode<T>* currentItem, ListNode<T>* insertItem){};
    virtual T remove(T item){};
    virtual T removeFront(){};
    virtual int search(T item){};
    virtual void print(){};
    virtual void sort(){};
    virtual bool isEmpty(){};
    virtual unsigned int getLength(){};
};

/*
template class myList
*/
template <class T>
class MyList : public ListInterface<T>
{
  public:
    MyList();
    ~MyList();
    void append(T item);
    void prepend(T item);
    void insertAfter(ListNode<T>* currentItem, ListNode<T>* insertItem);
    T remove(T item);
    T removeFront();
    int search(T item);
    T viewFront();
    void print();
    void sort();
    bool isEmpty();
    unsigned int getLength();
  private:
    DoublyLinkedList<T> *myLinkedList;
};

/*
Function: MyList()
Return: T
Parameters: none (default constructor)
Exceptions: none
*/
//instatiates a new DoublyLinkedList
template <class T>
MyList<T>::MyList(){
  myLinkedList = new DoublyLinkedList<T>();
}

/*
Function: ~MyList()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
MyList<T>::~MyList(){
  delete myLinkedList;
}

/*
Function: append()
Return: none
Parameters: T item
Exceptions: none
*/
//appends iteam to the back of the list
template <class T>
void MyList<T>::append(T item) {
  myLinkedList->insertBack(item);
}

/*
Function: prepend()
Return: none
Parameters: T item
Exceptions: none
*/
//inserts item into the front of the list
template <class T>
void MyList<T>::prepend(T item) {
  myLinkedList->insertFront(item);
}

/*
Function: insertAfter()
Return: none
Parameters: ListNode<T> *currentItem, ListNode<T> *insertItem
Exceptions: none
*/
//inserts insertItem affter currentItem in the list
template <class T>
void MyList<T>::insertAfter(ListNode<T>* currentItem, ListNode<T>* insertItem) {
  myLinkedList->insertAfter(currentItem, insertItem);
}

/*
Function: remove()
Return: T
Parameters: T item
Exceptions: none
*/
//takes in a data value, then removes the node with that value and returns the data
template <class T>
T MyList<T>::remove(T item) {
  return myLinkedList->removeNode(item);
}

/*
Function: search()
Return: int
Parameters: T item
Exceptions: none
*/
//takes in a data value, finds it in the list, and returns its position as an int
template <class T>
int MyList<T>::search(T item) {
  return myLinkedList->find(item);
}

/*
Function: viewFront()
Return: T
Parameters: none
Exceptions: none
*/
//returns the front data
template <class T>
T MyList<T>::viewFront() {
  return myLinkedList->getFront();
}

/*
Function: print()
Return: none
Parameters: none
Exceptions: none
*/
//prints out the List, bool parameter will print the links if passed in true
template <class T>
void MyList<T>::print() {
  bool printLink = false;
  myLinkedList->printList(printLink);
}

/*
Function: sort()
Return: none
Parameters: none
Exceptions: none
*/
//sorts the List from low to high data values using the bubble sort technique
template <class T>
void MyList<T>::sort() {
  myLinkedList->sort();
}

/*
Function: isEmpty()
Return: bool
Parameters: none
Exceptions: none
*/
//returns a bool checking if the list is empty
template <class T>
bool MyList<T>::isEmpty() {
  return (myLinkedList->isEmpty());
}

/*
Function: getLength()
Return: int
Parameters: none
Exceptions: none
*/
//returns an int of the length of the list
template <class T>
unsigned int MyList<T>::getLength() {
  return myLinkedList->getSize();
}

/*
Function: removeFront()
Return: T
Parameters: none
Exceptions: none
*/
//removes the front of the list and returns its data
template <class T>
T MyList<T>::removeFront(){
  return myLinkedList->removeFront();
}

//end of the header guards
#endif
