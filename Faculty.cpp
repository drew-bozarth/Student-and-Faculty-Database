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
  val = -1;
}

Faculty::Faculty(int facultyID, string name, string level, string department){
  //overloaded constructor
  mFacultyID = facultyID;
  mName = name;
  mLevel = level;
  mDepartment = department;
  mStudentIDList = new MyList<int>;
  val = -1;
}

Faculty::~Faculty(){
  //destructor
  delete mStudentIDList;
}

bool Faculty::operator==(Faculty& rhf){
  return (getID() == rhf.getID());
}
bool Faculty::operator!=(Faculty& rhf){
  return (getID() != rhf.getID());
}
bool Faculty::operator<=(Faculty& rhf){
  return (getID() <= rhf.getID());
}
bool Faculty::operator>=(Faculty& rhf){
  return (getID() >= rhf.getID());
}
bool Faculty::operator<(Faculty& rhf){
  return (getID() < rhf.getID());
}
bool Faculty::operator>(Faculty& rhf){
  return (getID() > rhf.getID());
}
ostream& operator<<(ostream& os, Faculty& fac){
  os << fac.toString();
  return os;
}

string Faculty::toString(){
  string s;
  s += "\n------------------------------";
  s += "\nFaculty Member: " + mName;
  s += "\nID Number: " + to_string(mFacultyID);
  s += "\nLevel: " + mLevel;
  s += "\nDepartment: " + mDepartment;
  s += "\n------------------------------";
  s += "\nStudents: ";
  s += "\n---------\n";
  s += printStudents();
  return s;
}

string Faculty::toFile(){
  string str;
  str += to_string(mFacultyID) + ",";
  str += mName + ",";
  str += mLevel + ",";
  str += mDepartment + ",";
  str += printStudents();
  return str;
}

int Faculty::getID(){
  return mFacultyID;
}
string Faculty::getName(){
  return mName;
}
string Faculty::getLevel(){
  return mLevel;
}
string Faculty::getFacultyDepartment(){
  return mDepartment;
}
void Faculty::setFacultyID(int id){
  mFacultyID = id;
}

void Faculty::AddStudent(int num){
  mStudentIDList->append(num);
}
void Faculty::removeStudent(int num){
  if (mStudentIDList->getLength() > 0){
    mStudentIDList->remove(num);
  }
 }
string Faculty::printStudents(){
  string s = "(";
  int temp;
  for (int i = 0; i < mStudentIDList->getLength(); ++i){
    temp = mStudentIDList->removeFront();
    s += to_string(temp) + ",";
    mStudentIDList->append(temp);
  }
  s += ")";
  return s;
}
