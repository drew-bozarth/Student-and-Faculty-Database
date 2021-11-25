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
#include "Person.h"
//standard namespace libaray in C++
using namespace std;

class Student: public Person{
public:
  Student();
  Student(int studentID, string name, string level, string major, double studentGPA, int advisorID);
  ~Student();
  void toString() override;
  int getID() override;
  string getName() override;
  string getLevel() override;
  string getStudentMajor();
  double getStudentGPA();
  int getAdvisorID();
  void setAdvisorID(int a);

  void print();
private:
  int mStudentID;
  string mName;
  string mLevel;
  string mMajor;
  double mStudentGPA;
  int mAdvisorID;
};
//end of the header guards
#endif
