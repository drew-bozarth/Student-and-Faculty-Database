/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Student.h */

/*
This is the .h file for Student
*/

//these are the header guards
#ifndef STUDENT_H
#define STUDENT_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
#include <string>
//these include user defined files
#include "Person.h"
//standard namespace libaray in C++
using namespace std;

class Student: public Person{
public:
  Student();
  Student(int studentID, string name, string level, string major, double studentGPA, int advisorID);
  ~Student();

  bool operator==(Student& rhs);
  bool operator!=(Student& rhs);
  bool operator>=(Student& rhs);
  bool operator<=(Student& rhs);
  bool operator>(Student& rhs);
  bool operator<(Student& rhs);
  friend ostream& operator<<(ostream& os, Student& stu);
//override functions from virtual class
  string toString() override;
  int getID() override;
  string getName() override;
  string getLevel() override;
  //student specific functions
  string getStudentMajor();
  double getStudentGPA();
  int getAdvisorID();
  void setAdvisorID(int a);
  void setStudentID(int id);
  string toFile() override;

private:
  //variables
  int mStudentID;
  string mName;
  string mLevel;
  string mMajor;
  double mStudentGPA;
  int mAdvisorID;
};
//end of the header guards
#endif
