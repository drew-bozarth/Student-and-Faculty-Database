/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Simulation.cpp */

/*
This is the .cpp file for Simulation
*/

//this statement includes the Simulation.h file
#include "Simulation.h"


Simulation::Simulation(){
  //default constructor
  studentDB = new BST<Student>();
  facultyDB = new BST<Faculty>();
  stack = new GenStack<DatabaseOperations<Person>>();
  rollbackCount = 0;
}

Simulation::~Simulation(){
  //destructor
  delete studentDB;
  delete facultyDB;
  delete stack;
}

void Simulation::start(){
  bool fileProcessed = fileProcessor();
  if (!fileProcessed){
    cout << "No file, blank databases" << endl;
    return;
  }
}

void Simulation::simulate(){
  try{
    bool userExit = false;
    while (!userExit){
      cout << "--------------------------------------------------------------------------------------------------" << endl;
      cout << "Welcome to the School Database! Please enter the number for the action which you wish to complete!" << endl;
      cout << "--------------------------------------------------------------------------------------------------" << endl;
      cout << "\n" << endl;
      cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
      cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
      cout << "3. Find and display student information given the students id" << endl;
      cout << "4. Find and display faculty information given the faculty id" << endl;
      cout << "5. Given a student's id, print the name and info of their faculty advisor" << endl;
      cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl;
      cout << "7. Add a new student" << endl;
      cout << "8. Delete a student given the id" << endl;
      cout << "9. Add a new faculty member" << endl;
      cout << "10. Delete a faculty member given the id" << endl;
      cout << "11. Change a student's advisor given the student id and the new faculty id" << endl;
      cout << "12. Remove an advisee from a faculty member given the id" << endl;
      cout << "13. Rollback" << endl;
      cout << "14. Save and Exit" << endl;
      cout << "15. Exit Without Saving" << endl;
      int userInput;
      cin >> userInput;

      if (userInput == 1){
        //1. Print all students and their information (sorted by ascending id #)
        printAllStudentInfo();
      }
      else if (userInput == 2){
        //2. Print all faculty and their information (sorted by ascending id #)
        printAllFalcultyInfo();
      }
      else if (userInput == 3){
        //3. Find and display student information given the students id
        displayStudentInfo();
      }
      else if (userInput == 4){
        //4. Find and display faculty information given the faculty id
        displayFacultyInfo();
      }
      else if (userInput == 5){
        //5. Given a student's id, print the name and info of their faculty advisor
        displayStudentAdvisor();
      }
      else if (userInput == 6){
        //6. Given a faculty id, print ALL the names and info of his/her advisees
        displayAllAdvisees();
      }
      else if (userInput == 7){
        //7. Add a new student
        addStudent();
      }
      else if (userInput == 8){
        //8. Delete a student given the id
        deleteStudent();
      }
      else if (userInput == 9){
        //9. Add a new faculty member
        addFaculty();
      }
      else if (userInput == 10){
        //10. Delete a faculty member given the id
        deleteFaculty();
      }
      else if (userInput == 11){
        //11. Change a student's advisor given the student id and the new faculty id
        changeAdvisor();
      }
      else if (userInput == 12){
        //12. Remove an advisee from a faculty member given the id
        removeAdvisee();
      }
      else if (userInput == 13){
        //13. Rollback
        rollback();
      }
      else if (userInput == 14){
        //14. Exit
        userExit = true;
        exitAndSave();
        cout << "Thank you goodbye." << endl;
        return;
      }
      else if (userInput == 15){
        userExit = true;
        cout << "Thank you goodbye." << endl;
        return;
      }
      else {
        cout << "Sorry that was not a valid option, please try again" << endl;
      }
    }
  }

  catch(runtime_error &excpt){
    cerr << excpt.what() << endl;
  }
}

//1.
void Simulation::printAllStudentInfo(){
  if (studentDB->isEmpty()){
    cout << "Student Database is Empty!!!" << endl;
    return;
  }
  else{
    studentDB->printNodes();
  }
}

//2.
void Simulation::printAllFalcultyInfo(){
  if (facultyDB->isEmpty()){
    cout << "Faculty Database is Empty!!!" << endl;
    return;
  }
  else {
    facultyDB->printNodes();
  }
}

//3.
void Simulation::displayStudentInfo(){
  int studentID = -1;
  while ((studentID < 1000000) || (studentID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID number of the Student you wish to display: ";
    cin >> studentID;
  }
  Student *stu = new Student();
  stu->setStudentID(studentID);
  if (studentDB->contains(stu)){
    studentDB->printNode(stu);
  }
  else {
    cout << "Sorry, that Student ID does not match any Student in the Database!" << endl;
    return;
  }
}

//4.
void Simulation::displayFacultyInfo(){
  int facultyID = -1;
  while ((facultyID < 1000000) || (facultyID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID number of the Faculty you wish to display: ";
    cin >> facultyID;
  }
  Faculty *fac = new Faculty();
  fac->setFacultyID(facultyID);
  if (facultyDB->contains(fac)){
    facultyDB->printNode(fac);
  }
  else {
    cout << "Sorry, that Faculty ID does not match any Faculty in the Database!" << endl;
    return;
  }
}

//5.
void Simulation::displayStudentAdvisor(){
  int studentID = -1;
  while ((studentID < 1000000) || (studentID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the ID number of the student who's advisor you wish to display: ";
    cin >> studentID;
  }
  Student *stu = new Student();
  stu->setStudentID(studentID);
  if (studentDB->contains(stu)){
    int advisorID = studentDB->find(stu)->getAdvisorID();
    Faculty *fac = new Faculty();
    fac->setFacultyID(advisorID);
    if (facultyDB->contains(fac)){
      cout << "Advisor: " << endl;
      facultyDB->printNode(fac);
    }
    else{
      cout << "Sorry, that Student's Advisor does not match any Faculty in the Database!" << endl;
      return;
    }
  }
  else {
    cout << "Sorry, that Student ID does not match any Student in the Database!" << endl;
    return;
  }
}

//6.
void Simulation::displayAllAdvisees(){
  int facultyID;
  cout << "Enter the ID number of the faculty to display all of their advisees: ";
  cin >> facultyID;
  Faculty *fac = new Faculty();
  fac->setFacultyID(facultyID);
  cout << facultyDB->find(fac)->printStudents() << endl;
}

//7.
void Simulation::addStudent(){
  int newID = -1;
  while ((newID < 1000000) || (newID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the ID for the new Student: ";
    cin >> newID;
  }
  string newName = "";
  string first = "";
  string last = "";
  while (cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the first name for the new Student: ";
    cin >> first;
    cout << "Enter the last name for the new Student: ";
    cin >> last;
  }
  newName = first + " " + last;
  string newLevel = "";
  while (cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the level for the new Student: ";
    cin >> newLevel;
  }
  string newMajor = "";
  while (cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the major for the new Student: ";
    cin >> newMajor;
  }
  double newGPA = 0.0;
  while ((newGPA < 0.0) || (newGPA > 5.0) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the GPA for the new Student: ";
    cin >> newGPA;
  }

  int newAdvisorID = 0;
  while ((newAdvisorID < 1000000) || (newAdvisorID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the ID of the advisor for the new Student: ";
    cin >> newAdvisorID;
    Faculty *fac = new Faculty();
    fac->setFacultyID(newAdvisorID);
    if (!(facultyDB->contains(fac))){
      cout << "Sorry, that Advisor ID does not match any Faculty in the Database!" << endl;
      newAdvisorID = -1;
    }
  }
  
  Student *newStudent = new Student(newID, newName, newLevel, newMajor, newGPA, newAdvisorID);
  studentDB->insert(newStudent);
  //DatabaseOperations<Student> *operation = new DatabaseOperations<Student>(0,true,studentDB->getObject(newID));
  //stack->push(operation);
  rollbackCount = 0;
}

//8.
void Simulation::deleteStudent(){
  int studentID;
  cout << "Enter the ID number of the student you wish to delete: ";
  cin >> studentID;
  Student *stu = new Student();
  stu->setStudentID(studentID);
  //DatabaseOperations<Student> *operation = new DatabaseOperations<Student>(1,true,studentDB->getObject(stu));
  //stack->push(operation);
  rollbackCount = 0;

  studentDB->deleteNode(stu);
}

//9.
void Simulation::addFaculty(){
  int newID;
  cout << "Enter the ID for the new Advisor: ";
  cin >> newID;
  string newName = "";
  cout << "Enter the name for the new Advisor: ";
  cin >> newName;
  string newLevel = "";
  cout << "Enter the level for the new Advisor: ";
  cin >> newLevel;
  string newDepartment = "";
  cout << "Enter the deparment for the new Advisor: ";
  cin >> newDepartment;
  int newIDListSize = 10;
  Faculty *newFaculty = new Faculty(newID, newName, newLevel, newDepartment);
  facultyDB->insert(newFaculty);
  //DatabaseOperations<Faculty> *operation = new DatabaseOperations<Faculty>(0,false,facultyDB->getObject(newID));
  //stack->push(operation);
  rollbackCount = 0;
}

//10.
void Simulation::deleteFaculty(){
  int facultyID;
  cout << "Enter the ID number of the faculty member you wish to delete: ";
  cin >> facultyID;
  Faculty *fac = new Faculty();
  fac->setFacultyID(facultyID);
  //DatabaseOperations<Faculty> *operation = new DatabaseOperations<Faculty>(1,false,facultyDB->getObject(fac));
  //stack->push(operation);
  rollbackCount = 0;

  facultyDB->deleteNode(fac);
}

//11.
void Simulation::changeAdvisor(){
  int studentID;
  cout << "Enter the ID number of the student who needs their advisor changed: ";
  cin >> studentID;
  int facultyID;
  cout << "Enter the ID number of the new advisor: ";
  cin >> facultyID;
  Student *stu = new Student();
  stu->setStudentID(studentID);
  studentDB->find(stu)->setAdvisorID(facultyID);
}

//12.
void Simulation::removeAdvisee(){
  int facultyID;
  cout << "Enter the ID number of the faculty member you wish to edit: ";
  cin >> facultyID;
  int studentID;
  cout << "Enter the ID number of the advisee you wish to remove: ";
  cin >> studentID;
  //edit list of faculty and remove the student ID
}

//13.

void Simulation::rollback(){
  /*
  if (stack->isEmpty()){
    throw runtime_error("Stack is empty, there are no actions to undo!");
  }
  if (rollbackCount >= 5){
    cout << "Sorry, you are only able to rollback 5 times continously." << endl;
    return;
  }

  int action = stack->peek()->getAction();
  bool isStudent = stack->peek()->isStudent();
  if (isStudent){
    if (action == 0){
      int studentID = stack->pop()->getObject()->getStudentID();
      studentDB->deleteObject(studentID);
    }
    else if (action == 1){
      int studentID = stack->peek()->getObject()->getStudentID();
      string name = stack->peek()->getObject()->getStudentName();
      string level = stack->peek()->getObject()->getStudentLevel();
      string major = stack->peek()->getObject()->getStudentMajor();
      double studentGPA = stack->peek()->getObject()->getStudentGPA();
      int advisorID = stack->pop()->getObject()->getAdvisorID();
      Student* stu = new Student(studentID, name, level, major, studentGPA, advisorID);
      studentDB->addObject(stu);
    }
    else {
      throw runtime_error("Rollback action doesn't exist!");
    }
  }
  else{
    if (action == 0){
      int facultyID = stack->pop()->getObject()->getFacultyID();
      facultyDB->deleteObject(facultyID);
    }
    else if (action == 1){
      int facultyID = stack->peek()->getObject()->getFacultyID();
      string name = stack->peek()->getObject()->getFacultyName();
      string level = stack->peek()->getObject()->getFacultyLevel();
      string department = stack->peek()->getObject()->getFacultyMajor();
      Faculty* fac = new Faculty(facultyID, name, level, department);
      facultyDB->addObject(fac);
    }
    else {
      throw runtime_error("Rollback action doesn't exist!");
    }
  }
  ++rollbackCount;
  */
}


//14.
void Simulation::exitAndSave(){
  /*
  //uhhhh idk
  //needs to save out current databases to a file
  ofstream studentFile {"studentTable.txt"};
  ofstream facultyFile {"facultyTable.txt"};
  string resultFac;
  string resultStu;
  resultFac = facultyDB->storeDB();
  resultStu = studentDB->storeDB();
  studentFile << resultStu << endl;
  facultyFile << resultFac << endl;

  //needs to "clean up"
  //then exit
  */
}

bool Simulation::fileProcessor(){
  return false;
  /*
  string studentArray[6];
  string facultyArray[4];
  //if file successfully opens, need to read binary file and
  // re-create databases
  ifstream facultyInput;
  facultyInput.open("facultyTable.txt");
  ifstream studentInput;
  studentInput.open("studentTable.txt");

  if (facultyInput.is_open() && studentInput.is_open()){
    //read files and create trees
    string str;
    getline(studentInput, str);
    int k = 0;
    while(getline(studentInput,str)){
      int stuID = 0;
      string stuName = "";
      string year = "";
      string stuMajor = "";
      double stuGPA = 0.0;
      int advisorID = 0;
      string s;
      for (int i = 0; i < str.size(); ++i){
        if (str[i] != ','){
          s += str[i];
        } else {
          studentArray[k] = s;
          ++k;
        }
      }
      stuID = stoi(studentArray[0]);
      stuName = studentArray[1];
      year = studentArray[2];
      stuMajor = studentArray[3];
      stuGPA = stod(studentArray[4]);
      advisorID = stoi(studentArray[5]);
      Student *newStudent = new Student(stuID, stuName, year, stuMajor, stuGPA, advisorID);
      studentDB->addObject(newStudent);
    }
    getline(facultyInput, str);
    while(getline(facultyInput,str)){
      int facID = 0;
      string facName = "";
      string job = "";
      string facDepartment = "";
      string s;
      for (int i = 0; i < str.size(); ++i){
        if (str[i] != ','){
          s += str[i];
        } else {
          facultyArray[k] = s;
          ++k;
        }
      }
      facID = stoi(facultyArray[0]);
      facName = facultyArray[1];
      job = facultyArray[2];
      facDepartment = facultyArray[3];
      Faculty *newFaculty = new Faculty(facID, facName, job, facDepartment);
      facultyDB->addObject(newFaculty);
    }



    facultyInput.close();
    studentInput.close();

    return true;
  }
  else {
    return false;
  }
  */
}
