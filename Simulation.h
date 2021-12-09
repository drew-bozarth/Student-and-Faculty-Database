/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Simulation.h */

/*
This is the .h file for Simulation
*/

//these are the header guards
#ifndef SIMULATION_H
#define SIMULATION_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <limits>

#include "bst.h"
#include "GenStack.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include "DatabaseOperations.h"
//standard namespace libaray in C++
using namespace std;

class Simulation{
public:
  Simulation();
  ~Simulation();

  void start();
  void simulate();
  bool fileProcessor();

  void printAllStudentInfo();
  void printAllFalcultyInfo();
  void displayStudentInfo();
  void displayFacultyInfo();
  void displayStudentAdvisor();
  void displayAllAdvisees();
  void addStudent();
  void deleteStudent();
  void addFaculty();
  void deleteFaculty();
  void changeAdvisor();
  void removeAdvisee();
  void rollback();
  void exitAndSave();
private:
  BST<Student> *studentDB;
  BST<Faculty> *facultyDB;
  GenStack<DatabaseOperations<Person>> *stack;
  int rollbackCount;

};
//end of the header guards
#endif
