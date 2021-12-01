/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - GenStack.h */

//these are the header guards
#ifndef GENSTACK_H
#define GENSTACK_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//standard namespace libaray in C++
using namespace std;

#include "LinkedList.h"

/*
Template Class: GenStack
*/
template <class T>
class GenStack{
  public:
    GenStack(); //default constructor
    virtual ~GenStack(); //destructor

    //core function
    void push(T data);
    T pop();

    //aux/helper functions
    T peek(); //aka top()
    bool isEmpty();
    bool isFull();
    unsigned int getSize();

  private:
    DoublyLinkedList<T> *stack;
};

/*
Function: GenStack()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
template <class T>
GenStack<T>::GenStack(){
  stack = new DoublyLinkedList<T>();
}

/*
Function: ~GenStack()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
GenStack<T>::~GenStack(){
  delete stack;
}

/*
Function: push
Return: void
Parameters: T data (Type T for template class)
Exceptions: none
*/
//adds an item to the top of the stack
template <class T>
void GenStack<T>::push(T data){
  stack->insertFront(data);
}

/*
Function: pop()
Return: T (Type T for template class)
Parameters: none
Exceptions: none
*/
//returns and removes the item at the top of the stack
template <class T>
T GenStack<T>::pop(){
  return stack->removeFront();
}

/*
Function: peek()
Return: T (Type T for template class)
Parameters: none
Exceptions: none
*/
//returns the item at the top of the stack without removing it
template <class T>
T GenStack<T>::peek(){
  return stack->getFront();
}

/*
Function: isEmpty()
Return: bool
Parameters: none
Exceptions: none
*/
//returns bool value that checks if the stack is empty
template <class T>
bool GenStack<T>::isEmpty(){
  return stack->isEmpty();
}

/*
Function: getSize()
Return: unsigned int (the size of the stack will always be positive int)
Parameters: none
Exceptions: none
*/
//returns the number of elemennts in the stack
template <class T>
unsigned int GenStack<T>::getSize(){
  return stack->getSize();
}
//end of the header guards
#endif
