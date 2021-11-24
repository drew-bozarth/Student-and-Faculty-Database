/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Faculty.h */

/*
This is the .h file for Faculty
*/

//these are the header guards
#ifndef FACULTY_H
#define FACULTY_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
#include <string>
#include "ListInterface.h"
// #include "Person.h"
//standard namespace libaray in C++
using namespace std;

class Faculty{
public:
  Faculty();
  Faculty(int facultyID, string fName, string fLevel, string fDepartment, int IDListSize);
  ~Faculty();
  // int getID();
  // string getName();
  // string getLevel();
  // void toString() override;
  void printFaculty();
  int getFacultyID();
  string getFacultyDepartment();
  string getFacultyName();
  string getFacultyLevel();
  void printStudents();
  void AddStudent(int num);
  void removeStudent(int num);
private:
  int id;
  string name;
  string level;
  string department;
  MyList<int> *StudIDList;
};
//end of the header guards
#endif
