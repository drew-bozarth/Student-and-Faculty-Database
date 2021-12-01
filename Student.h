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
//standard namespace libaray in C++
using namespace std;

class Student{
public:
  Student();
  Student(int studentID, string name, string level, string major, double studentGPA, int advisorID);
  ~Student();
  string printStudent();
  int getStudentID();
  string getStudentName();
  string getStudentLevel();
  string getStudentMajor();
  double getStudentGPA();
  int getAdvisorID();

  void setAdvisorID(int a);
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
