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
  mIDList = new int[0];
}

Faculty::Faculty(int facultyID, string name, string level, string department, int IDListSize){
  //overloaded constructor
  mFacultyID = facultyID;
  mName = name;
  mLevel = level;
  mDepartment = department;
  mIDList = new int[IDListSize];
}

Faculty::~Faculty(){
  //destructor
}
string Faculty::printFaculty(){
  //print everything
};
int Faculty::getFacultyID(){
  return id;
};
string Faculty::getFacultyDepartment(){
  return department;
};
string Faculty::getFacultyName(){
  return name;
};
string Faculty::getFacultyLevel(){
  return level;
};
string Faculty::printStudents(){
  //print list
};
void Faculty::AddStudent(int num){
  student->append(num);
};
void Faculty::removeStudent(int num){
  student->removeValue(num);
};
