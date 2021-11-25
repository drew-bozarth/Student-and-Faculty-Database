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
  mIDList = new MyList<int>;
}

Faculty::Faculty(int facultyID, string name, string level, string department){
  //overloaded constructor
  mFacultyID = facultyID;
  mName = name;
  mLevel = level;
  mDepartment = department;
}

Faculty::~Faculty(){
  //destructor
}
void Faculty::toString(){
  cout << "Faculty member: " << name;
  cout << " | ID number: " << id;
  cout << " | Level: " << level;
  cout << " | department: " << deparment;
  cout << "\n Students: " << printStudents();
  cout << "\n";
};
int Faculty::getID(){
  return mFacultyID;
};
string Faculty::getFacultyDepartment(){
  return department;
};
string Faculty::getName(){
  return mName;
};
string Faculty::getFacultyLevel(){
  return level;
};
void Faculty::printStudents(){
  StudIDList->print();
};
void Faculty::AddStudent(int num){
  student->append(num);
};
void Faculty::removeStudent(int num){
  student->remove(num);
};
