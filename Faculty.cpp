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
