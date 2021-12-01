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

using namespace std;

/*
Template Class: Database
*/
template <class T>
class Database{
  public:
    Database(); //default constructor
    virtual ~Database(); //destructor

    void printDB();
    void displayObejct(int objectID);
    void displayStudentAdvisor(int studentID);
    void displayAllAdvisees(int facultyID);
    void addStudent(int newID, string newName, string newLevel, string newMajor, double newGPA, int newAdvisorID);
    void addFaculty(int newID, string newName, string newLevel, string newDepartment, int newIDListSize);
    void deleteObject(int objectID);
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



#endif
