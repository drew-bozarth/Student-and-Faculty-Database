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
  id = -1;
  name = "";
  level = "";
  mDepartment = "";
  mIDList = new MyList<int>;
}

Faculty::Faculty(int facultyID, string fName, string fLevel, string department){
  //overloaded constructor
  id = facultyID;
  name = fName;
  level = fLevel;
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
// int Faculty::getFacultyID(){
//   return id;
// };
string Faculty::getFacultyDepartment(){
  return department;
};
// string Faculty::getFacultyName(){
//   return name;
// };
// string Faculty::getFacultyLevel(){
//   return level;
// };
string Faculty::printStudents(){
  string s;
  s = StudIDList->print();
  return s;
};
void Faculty::AddStudent(int num){
  student->append(num);
};
void Faculty::removeStudent(int num){
  student->remove(num);
};
