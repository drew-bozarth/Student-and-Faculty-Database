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

int Faculty::getFacultyID(){
  return mFacultyID;
}

string Faculty::getFacultyName(){
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
void Faculty::printStudents(){
  string s;
  s = mStudentIDList->print();
  cout << s;
}

void Faculty::print(){
  string s;
  s += "Faculty member: " + mName;
  s += " | ID number: " + mFacultyID;
  s += " | Level: " + mLevel;
  s += " | department: " + mDeparment;
  s += "\n Students: " + printStudents();
  s += "\n";
  cout << s << endl;
}
