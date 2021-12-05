/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Database.h */

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <exception>

#include "bst.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

/*
Template Class: Database
*/
template <class T>
class Database{
  public:
    Database(); //default constructor
    virtual ~Database(); //destructor

    void addObject(T object);
    void deleteObject(int objectID);
    void getObject(int objectID);

    void printDB();
    void displayObejct(int objectID);
    void displayAllAdvisees(int facultyID);

    void changeAdvisor(int studentID, int facultyID);
    void removeAdvisee(int facultyID, int studentID);

  private:
    BST<T> *bst;
};

template <class T>
Database<T>::Database(){
  bst = new BST<T>();
}

template <class T>
Database<T>::~Database(){
  delete bst;
}

template <class T>
Databse<T>::addObject(T object){
  bst->insert(object);
}

template <class T>
Database<T>::deleteObject(int objectID){
  bst->deleteNode(objectID);
}

template <class T>
Database<T>::printDB(){
  bst->printNodes();
}

template <class T>
Database<T>::displayObejct(int objectID){
  bst->getObject(objectID)->print();
}

template <class T>
void Database<T>::displayAllAdvisees(int facultyID){

}

template <class T>
void Database<T>::changeAdvisor(int studentID, int facultyID){

}

template <class T>
void Database<T>::removeAdvisee(int facultyID, int studentID){

}




#endif
