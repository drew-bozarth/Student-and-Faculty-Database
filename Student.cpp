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
  return (getID() == rhs.getID());
}
bool Student::operator!=(Student& rhs){
  return (getID() != rhs.getID());
}
bool Student::operator<=(Student& rhs){
  return (getID() <= rhs.getID());
}
bool Student::operator>=(Student& rhs){
  return (getID() >= rhs.getID());
}
bool Student::operator<(Student& rhs){
  return (getID() < rhs.getID());
}
bool Student::operator>(Student& rhs){
  return (getID() > rhs.getID());
}
ostream& operator<<(ostream& os, Student& stu){
  os << stu.toString();
  return os;
}

int Student::getID(){
  return mStudentID;
}
string Student::getName(){
  return mName;
}
string Student::getLevel(){
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
void Student::setStudentID(int id){
  mStudentID = id;
}

string Student::toString(){
  string str;
  str += "Student Name: " + mName;
  str += " | ID number: " + mStudentID;
  str += " | Major: " + mMajor;
  str += " | Year: " + mLevel;
  str += " | GPA: " + to_string(mStudentGPA);
  str += " | Advisor ID: " + mAdvisorID;
  // str += "| \n"
  return str;
}
