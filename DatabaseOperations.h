/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - DatabaseOperations.h */

#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H

#include <iostream>
#include <exception>

using namespace std;

/*
Template Class: DatabaseOperations
*/
template <class T>
class DatabaseOperations{
  public:
    DatabaseOperations(); //default constructor
    DatabaseOperations(int action, T *object);
    virtual ~DatabaseOperations(); //destructor
    int getAction();
    bool isStudent();
    T* getObject();
  private:
    int mAction;
    bool mIsStudent;
    T *mObject;

};

template <class T>
DatabaseOperations<T>::DatabaseOperations(){

}

template <class T>
DatabaseOperations<T>::DatabaseOperations(int action, bool isStudent, T *object){
  mAction = action;
  mIsStudent = isStudent;
  mObject = object;
}

template <class T>
DatabaseOperations<T>::~DatabaseOperations(){

}

template <class T>
int DatabaseOperations<T>::getAction(){
  return mAction;
}

template <class T>
bool DatabaseOperations<T>::isStudent(){
  return mIsStudent;
}

template <class T>
T* DatabaseOperations<T>::getObject(){
  return mObject;
}


#endif
