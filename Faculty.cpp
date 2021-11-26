/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Faculty.cpp */

/*
This is the .cpp file for Faculty
*/

//this statement includes the Faculty.h file
#include "Faculty.h"


Faculty::Faculty(){
  //default constructor
  mFacultyID = -1;
  mName = "";
  mLevel = "";
  mDepartment = "";
  mStudentIDList = new MyList<int>;
}

Faculty::Faculty(int facultyID, string name, string level, string department){
  //overloaded constructor
  mFacultyID = facultyID;
  mName = name;
  mLevel = level;
  mDepartment = department;
  mStudentIDList = new MyList<int>;
}

Faculty::~Faculty(){
  //destructor
}

bool Faculty::operator==(Faculty& rhf){
  return (getID() == rhs->getID());
}
bool Faculty::operator!=(Faculty& rhf){
  return (getID() != rhs->getID());
}
bool Faculty::operator<=(Faculty& rhf){
  return (getID() <= rhs->getID());
}
bool Faculty::operator>=(Faculty& rhf){
  return (getID() >= rhs->getID());
}
bool Faculty::operator<(Faculty& rhf){
  return (getID() < rhs->getID());
}
bool Faculty::operator>(Faculty& rhf){
  return (getID() > rhs->getID());
}
friend bool Faculty::operator<<(ostream& ost, Faculty& fac){
  ost << fac;
  return ost;
}

string Faculty::toString(){
  string s;
  s += "Faculty member: " + name;
  s += " | ID number: " + id;
  s += " | Level: " + level;
  s += " | department: " + deparment;
  s += "\n Students: ";
  s += printStudents();
  return s;
}

int Faculty::getID(){
  return mFacultyID;
}
string Faculty::getName(){
  return mName;
}
string Faculty::getFacultyLevel(){
  return mLevel;
}
string Faculty::getFacultyDepartment(){
  return mDepartment;
}

void Faculty::AddStudent(int num){
  mStudentIDList->append(num);
}
void Faculty::removeStudent(int num){
  mStudentIDList->remove(num);
}
string Faculty::printStudents(){
  string s;
  s = mStudentIDList->print();
  return s;
}
