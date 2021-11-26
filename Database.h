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

    void addObject(T* object);
    void deleteObject(int objectID);
    T* getObject(int objectID);

    void printDB();
    void displayObejct(int objectID);
    void displayAdvisees(int facultyID);
    int displayAdvisorNum(int studentID);
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
void Database<T>::addObject(T* object){
  bst->insert(object);
}

template <class T>
void Database<T>::deleteObject(int objectID){
  bst->deleteNode(objectID);
}

template <class T>
T* Database<T>::getObject(int objectID){
  return bst->find(objectID);
}

template <class T>
void Database<T>::printDB(){
  bst->printNodes();
}

template <class T>
void Database<T>::displayObejct(int objectID){
  string s;
  s = bst->find(objectID)->toString();
  cout << s << endl;
}

// template <class T>
// void Database<T>::displayStudentAdvisor(int studentID){
//   Student stu;
//   Faculty fac;
//   int advisor;
//   stu = bst->find(studentID);
//   advisor = stu->getAdvisorID();
//   fac = bst->find(advisor);
//   fac->printFaculty();
// }

template <class T>
void Database<T>::displayAdvisees(int facultyID){
  Faculty *fac;
  fac = bst->find(facultyID);
  fac->printStudents();
}

template <class T>
void Database<T>::changeAdvisor(int studentID, int facultyID){
  Student *curr;
  curr = bst->find(studentID);
  curr->setAdvisorID(facultyID);
}

template <class T>
int Database<T>::displayAdvisorNum(int studentID){
  Student *stu;
  stu = bst->find(studentID);
  int adv;
  adv = stu->getAdvisorID();
  return adv;
}

#endif
