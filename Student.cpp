/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Student.cpp */

/*
This is the .cpp file for Student
*/

//this statement includes the Student.h file
#include "Student.h"


Student::Student(){
  //default constructor
  mStudentID = -1;
  mName = "";
  mLevel = "";
  mMajor = "";
  mStudentGPA = -1.0;
  mAdvisorID = -1;
}

Student::Student(int studentID, string name, string level, string major, double studentGPA, int advisorID){
  //overloaded constructor
  mStudentID = studentID;
  mName = name;
  mLevel = level;
  mMajor = major;
  mStudentGPA = studentGPA;
  mAdvisorID = advisorID;
}

Student::~Student(){
  //destructor
}

int Student::getStudentID(){
  return mStudentID;
}

string Student::getStudentName(){
  return mName;
}

string Student::getStudentLevel(){
  return mLevel;
}

string Student::getStudentMajor(){
  return mMajor;
}

double Student::getStudentGPA(){
  return mStudentGPA;
}

int Student::getAdvisorID(){
  return mAdvisorID;
}

void Student::setAdvisorID(int a){
  mAdvisorID = a;
}

void Student::print(){
  string s;
  s += "Student Name: " + mName;
  s += " | ID number: " + mStudentID;
  s += " | Year: " + mLevel;
  s += " | GPA: " + mStudentGPA;
  s += " | Advisor ID: " + mAdvisorID;
  s += "\n";
  cout << s << endl;
}
