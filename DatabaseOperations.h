/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - DatabaseOperations.h */

//these are the header guards
#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//standard namespace libaray in C++
using namespace std;

/*
Template Class: DatabaseOperations
*/
template <class T>
class DatabaseOperations{
  public:
    DatabaseOperations(); //default constructor
    DatabaseOperations(bool realOperation, int action, T *object); //overloaded constructor
    virtual ~DatabaseOperations(); //destructor
    bool isRealOperation();
    int getAction();
    T* getObject();
  private:
    bool mRealOperation;
    int mAction;
    T *mObject;

};

/*
Function: DatabaseOperations()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
template <class T>
DatabaseOperations<T>::DatabaseOperations(){
}
/*
Function: DatabaseOperations()
Return: none
Parameters: bool realOperation (indicates whether it is a real object or a dummy), int action (0 = remove, 1 = add), T* object (either the Student or Faculty object)
Exceptions: none
*/
template <class T>
DatabaseOperations<T>::DatabaseOperations(bool realOperation, int action, T *object){
  mRealOperation = realOperation;
  mAction = action;
  mObject = object;
}
/*
Function: GenStack()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
DatabaseOperations<T>::~DatabaseOperations(){
  mObject = NULL;
}
/*
Function: isRealOperation()
Return: bool
Parameters: none
Exceptions: none
*/
template <class T>
bool DatabaseOperations<T>::isRealOperation(){
  return mRealOperation;
}
/*
Function: getAction()
Return: int
Parameters: none
Exceptions: none
*/
template <class T>
int DatabaseOperations<T>::getAction(){
  return mAction;
}
/*
Function: getObject()
Return: T*
Parameters: none
Exceptions: none
*/
template <class T>
T* DatabaseOperations<T>::getObject(){
  return (mObject);
}

//end of the header guards
#endif
