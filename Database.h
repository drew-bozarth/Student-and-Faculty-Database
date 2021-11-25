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
#include "student.h"
#include "faculty.h"

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
    int displayAdvisorNum(int studentID);
    // void displayStudentAdvisor(int studentID); needs access to both trees/databases should be else where
    void displayAllAdvisees(int facultyID);
    void addStudent(int newID, string newName, string newLevel, string newMajor, double newGPA, int newAdvisorID);
    void deleteObject(int objectID);
    void addFaculty(int newID, string newName, string newLevel, string newDepartment);
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
void Database<T>::printDB(){
  bst->printNodes();
}

template <class T>
void Database<T>::displayObejct(int objectID){
  bst->find(objectID)->toString();
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
void Database<T>::displayAllAdvisees(int facultyID){
  Faculty *fac;
  fac = bst->find(facultyID);
  fac->printStudents();
}

template <class T>
void Database<T>::addStudent(int newID, string newName, string newLevel, string newMajor, double newGPA, int newAdvisorID){
  Student *newStu = new Student(newID, newName, newLevel, newMajor, newGPA, newAdvisorID);
  bst->insert(newStu);
}

template <class T>
void Database<T>::addFaculty(int newID, string newName, string newLevel, string newDepartment){
  Faculty *newFac = new Faculty(newID, newName, newLevel, newDepartment);
  bst->insert(newFac);
}

template <class T>
void Database<T>::deleteObject(int objectID){
  bst->deleteNode(objectID);
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
};



#endif
