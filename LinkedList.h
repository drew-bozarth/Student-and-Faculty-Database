/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - LinkedList.h */

/*
This is a template class for a Doubly LinkedList
*/

//these are the header guards
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//standard namespace libaray in C++
using namespace std;

/*
Template Class: ListNode
*/
template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    virtual ~ListNode();
    ListNode *next;
    ListNode *prev;
    T data;
};

/*
Function: ListNode()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
template <class T>
ListNode<T>::ListNode(){

}

/*
Function: ListNode(T d)
Return: none
Parameters: T d (Type is T for the template class)
Exceptions: none
*/
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

/*
Function: ~ListNode()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}


/*
Template Class: DoublyLinkedList
*/
template <class T>
class DoublyLinkedList{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
  public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList();
    void insertFront(T d);
    void insertBack(T d);
    void insertAfter(ListNode<T> *currentNode, ListNode<T> *newNode);
    T removeFront();
    T removeBack();
    T getFront();
    T removeNode(T value);
    int find(T value);
    bool isEmpty();
    unsigned int getSize();
    void printList(bool isPrintLink);
    void sort();
};

/*
Function: DoublyLinkedList()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

/*
Function: ~DoublyLinkedList()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  ListNode<T> *current = front;

  while (current != NULL){
    ListNode<T> *next = current->next;
    delete current;
    current = next;
  }
}

/*
Function: insertFront(T d)
Return: none
Parameters: data of type T
Exceptions: none
*/
//inserts node into the front of the linked list
template <class T>
void DoublyLinkedList<T>::insertFront(T d){

  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){
    back = node;
  }
  else{
    //it is not empty
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++size;
}

/*
Function: getFront()
Return: data of type T
Parameters: none
Exceptions: none
*/
//returns the front data
template<class T>
T DoublyLinkedList<T>::getFront(){
  return front->data;
}

/*
Function: insertBack()
Return: none
Parameters: data of type T
Exceptions: none
*/
//inserts node into the back of the linked list
template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  // cout << "in insertback" << endl;
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){
    // cout << "first node" << endl;
    front = node;
  }
  else{
    //it is not empty
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}

/*
Function: insertAfter()
Return: none
Parameters: ListNode<T> *currentNode, ListNode<T> *newNode
Exceptions: none
*/
//takes in two nodes, and inserts the seconds parameters after the first parameter in the linked list
template <class T>
void DoublyLinkedList<T>::insertAfter(ListNode<T> *currentNode, ListNode<T> *newNode){
  ListNode<T>* current = front;
  ListNode<T>* next = NULL;
  while (current != currentNode){
    next = current->next;
    current = next;
  }

  newNode->next = current->next;
  newNode->prev = current;
  current->next->prev = newNode;
  current->next = newNode;
}

/*
Function: removeFront()
Return: T
Parameters: none
Exceptions: none
*/
// removes the front node and returns the data
template <class T>
T DoublyLinkedList<T>::removeFront(){
  if (isEmpty()){
    throw runtime_error("list is empty!!");
  }

  ListNode<T> *temp = front;

  if(front->next == NULL){
    //only one node in the list and it's the front node
    back = NULL;
  }
  else{
    //more than one node in the list
    front->next->prev = NULL;
  }

  front = front->next;
  temp->next = NULL;
  T data = temp->data;
  --size;
  delete temp;

  return data;
}

/*
Function: removeBack()
Return: T
Parameters: none
Exceptions: none
*/
//removes the back node and returns the data
template <class T>
T DoublyLinkedList<T>::removeBack(){
  if (isEmpty()){
    throw runtime_error("list is empty!!");
  }

  ListNode<T> *temp = back;

  if (back->prev = NULL){
    //only one node in the list
    front = NULL;
  }
  else{
    //more than one node in the list
    back->prev->next = NULL;
  }

  back = back->prev;
  temp->prev = NULL;
  T data = temp->data;
  --size;
  delete temp;

  return data;
}

/*
Function: removeNode()
Return: T
Parameters: T value
Exceptions: none
*/
//takes in a data value, then removes the node with that value and returns the data
template <class T>
T DoublyLinkedList<T>::removeNode(T value){

  if (isEmpty()){
    throw runtime_error("list is empty");
  }

  //we can leverage the find method to decide whether we continue or not
  ListNode<T> *curr = front;
  while(curr->data != value){
    curr = curr->next;
    if(curr == NULL){
        throw runtime_error("node not found");
    }

  }

  //but we make it here, we found the value
  //we found it, let's proceed to remmove it

  if (curr == front){
    front = curr->next;
    front->prev = NULL;
  }
  if (curr == back){
    back = curr->prev;
    back->next = NULL;
  }
  if (curr != front && curr != back){
    //listnode is between front and back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  T data = curr->data;
  --size;

  delete curr;

  return data;
}

/*
Function: find()
Return: int
Parameters: T value
Exceptions: none
*/
//takes in a data value, finds it in the linked list, and returns its position as an int
template <class T>
int DoublyLinkedList<T>::find(T value){
  int pos = -1;
  ListNode<T> *curr = front;

  while (curr != NULL){
    ++pos;
    if(curr->data == value){
      break;
    }
    curr = curr->next;
  }
  if (curr == NULL)
    pos = -1;

  return pos;
}

/*
Function: getSize()
Return: unsigned int
Parameters: none
Exceptions: none
*/
//returns the size of the linked list (unsigned because size will always be positive)
template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

/*
Function: isEmpty()
Return: bool
Parameters: none
Exceptions: none
*/
//returns a boolean value checking if the linked list is empty
template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  // cout << "in is empty" << endl;
  return (size == 0);
}

/*
Function: printLink()
Return: none
Parameters: bool printLink
Exceptions: none
*/
//prints out the Linked List, bool parameter will print the links if passed in true
template <class T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: " << curr->prev << " || " << curr->data << " || NEXT: " << curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";
       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;
}

/*
Function: sort()
Return: none
Parameters: none
Exceptions: none
*/
//sorts the LinkedList from low to high data values using the bubble sort technique
template <class T>
void DoublyLinkedList<T>::sort() {
  if (isEmpty())
    return;

  bool isSorted = false;

  while (!isSorted){
    ListNode<T> *curr = front;
    int swapCount = 0;

    while (curr->next != NULL){
      if (curr->data > curr->next->data){
        T temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;
        swapCount = 1;
      }
      curr = curr->next;
    }

    if (swapCount == 0){
      isSorted = true;
    }
  }

}

//end of the header guards
#endif
