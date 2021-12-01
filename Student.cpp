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
int Student::getAdvisorID(){
  return advisorNum;
};

void Student::setAdvisorID(int a){
  advisorNum = a;
}

int Student::getStudentID(){
  return id;
};

double Student::getStudentGPA(){
  return gpa;
};
string Student::getStudentName(){
  return name;
};
string Student::getStudentLevel(){
  return level;
};
string Student::getMajor(){
  return major;
}
