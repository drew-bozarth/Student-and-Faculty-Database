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

bool Student::operator==(Student& rhs){
  return (getID() == rhs->getID());
}
bool Student::operator!=(Student& rhs){
  return (getID() != rhs->getID());
}
bool Student::operator<=(Student& rhs){
  return (getID() <= rhs->getID());
}
bool Student::operator>=(Student& rhs){
  return (getID() >= rhs->getID());
}
bool Student::operator<(Student& rhs){
  return (getID() < rhs->getID());
}
bool Student::operator>(Student& rhs){
  return (getID() > rhs->getID());
}
friend bool Student::operator<<(ostream& ostr, Student& stu){
  ostr << stu;
  return ostr;
}


int Student::getAdvisorID(){
  return mAdvisorID;
}

void Student::setAdvisorID(int a){
  mAdvisorID = a;
}

int Student::getID(){
  return mStudentID;
}

string Student::getStudentMajor(){
  return mMajor;
}

double Student::getStudentGPA(){
  return mStudentGPA;
}

string Student::getName(){
  return mName;
}

string Student::getLevel(){
  return mLevel;
}

void Student::toString(){
  cout << "Student Name: " << mName;
  cout << " | ID number: " << mStudentID;
  cout << " | Major: " << mMajor;
  cout << " | Year: " << mLevel;
  cout << " | GPA: " << mStudentGPA;
  cout << " | Advisor ID: " << mAdvisorID;
  cout << "| \n";
}
