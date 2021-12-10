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

/*
Function: Simulation()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
//instantiates the two BST databases and the two stacks, and sets rollback count to 0
Simulation::Simulation(){
  //default constructor
  studentDB = new BST<Student>();
  facultyDB = new BST<Faculty>();
  studentStack = new GenStack<DatabaseOperations<Student>>();
  facultyStack = new GenStack<DatabaseOperations<Faculty>>();
  rollbackCount = 0;
}
/*
Function: ~Simulation()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
Simulation::~Simulation(){
  //destructor deletes the databases and the stacks
  delete studentDB;
  delete facultyDB;
  delete studentStack;
  delete facultyStack;
}
/*
Function: start()
Return: none
Parameters: none
Exceptions: none
*/
// this calls the fileProcessor() method, and if it returns false, there were no files to process and the databases are blank
void Simulation::start(){
  bool fileProcessed = fileProcessor();
  if (!fileProcessed){
    cout << "No file found, blank databases created" << endl;
    return;
  }
}
/*
Function: simulate()
Return: none
Parameters: none
Exceptions: none
*/
/* this method is the main menu for the program. it will print out the menu and
allow you to select a given option until you choose to quit. If a valid input is given it
will call on a method corresponding to that action
*/
void Simulation::simulate(){
  try{
    bool userExit = false;
    while (!userExit){
      cout << "--------------------------------------------------------------------------------------------------" << endl;
      cout << "Welcome to the School Database! Please enter the number for the action which you wish to complete!" << endl;
      cout << "--------------------------------------------------------------------------------------------------" << endl;
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
        //14. Save and Exit
        userExit = true;
        exitAndSave();
        cout << "Thank you goodbye." << endl;
        return;
      }
      else if (userInput == 15){
        //15. Exit without saving
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
/*
Function: printAllStudentInfo()
Return: none
Parameters: none
Exceptions: none
*/
//checks if student database is empty, if not, prints whole database of students
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
/*
Function: printAllFalcultyInfo()
Return: none
Parameters: none
Exceptions: none
*/
//checks if faculty database is empty, if not, prints whole database of faculty
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
/*
Function: displayStudentInfo()
Return: none
Parameters: none
Exceptions: none
*/
//prompts for a valid student ID number, if the student exists, it will display their info
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
/*
Function: displayFacultyInfo()
Return: none
Parameters: none
Exceptions: none
*/
//prompts for a valid faculty ID number, if the faculty exists, it will display their info
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
/*
Function: displayStudentAdvisor()
Return: none
Parameters: none
Exceptions: none
*/
//prompts for a valid student ID number, if the student exists,
//it will check if their advisor exists in the Faculty Database and print them
void Simulation::displayStudentAdvisor(){
  int studentID = -1;
  while ((studentID < 1000000) || (studentID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID number of the student who's advisor you wish to display: ";
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
/*
Function: displayAllAdvisees()
Return: none
Parameters: none
Exceptions: none
*/
//prompts for a valid faculty ID, if they exist it loops through their list of students and prints each student's info
void Simulation::displayAllAdvisees(){
  int facultyID;
  string s;
  string temp = "";
  string final = "";
  int tempStuID;
  cout << "Enter the 7 digit ID number of the faculty to display all of their advisees: ";
  cin >> facultyID;
  Faculty *fac = new Faculty();
  Student *stu = new Student();
  fac->setFacultyID(facultyID);
  s = facultyDB->find(fac)->printStudents();
  for (int i = 1; i < s.size() - 1; ++i){
    // cout << "in for loop" << endl;
    if (s[i] != ','){
      temp += s[i];
    } else {
      // cout << "in else" << endl;
      // cout << temp << endl;
      tempStuID = stoi(temp);
      stu->setStudentID(tempStuID);
      final += studentDB->find(stu)->toString();
      temp = "";
    }
  }
  cout << final;
  delete fac;
  delete stu;
}

//7.
/*
Function: addStudent()
Return: none
Parameters: none
Exceptions: none
*/
/*prompts for valid entries of the required student info (ID,name,level,major,GPA,AdvisorID)
it will then check if the advisor ID exists in the database, if not it will not allow you to
add the student. If all the info is valid, it will create the student and add them to the
student database. It also is creating a database operation containing the student's info and
pushing it onto the studentStack and creating a dummy faculty opertaion for the facultyStack behind the scenes
*/
void Simulation::addStudent(){
  int newID = -1;
  while ((newID < 1000000) || (newID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID number for the new Student: ";
    cin >> newID;
  }

  string newName = "";
  string first = "\0";
  string last = "\0";
  while (first == "\0" || last == "\0" || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the first name for the new Student: ";
    cin >> first;
    cout << "Enter the last name for the new Student: ";
    cin >> last;
  }
  newName = first + " " + last;

  string newLevel = "\0";
  while (newLevel == "\0" || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the level for the new Student: ";
    cin >> newLevel;
  }

  string newMajor = "\0";
  while (newMajor == "\0" || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the major for the new Student: ";
    cin >> newMajor;
  }

  double newGPA = -1.0;
  while ((newGPA < 0.0) || (newGPA > 5.0) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the GPA for the new Student: ";
    cin >> newGPA;
  }

  int newAdvisorID = -1;
  while ((newAdvisorID < 1000000) || (newAdvisorID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID of the advisor for the new Student: ";
    cin >> newAdvisorID;
  }
  Faculty *fac = new Faculty();
  fac->setFacultyID(newAdvisorID);
  if (!(facultyDB->contains(fac))){
    cout << "Sorry, that Advisor ID does not match any Faculty in the Database!" << endl;
    cout << "Please use a valid Advisor ID in order to create a new Student" << endl;
    return;
  }

  Student *newStudent = new Student(newID, newName, newLevel, newMajor, newGPA, newAdvisorID);
  studentDB->insert(newStudent);
  facultyDB->find(fac)->AddStudent(newID);

  //this part adds an operation to both stacks, and the first parameter is a bool which indicates which operation is valid
  //these are to ensure the student and faculty stacks work as one and are on the same level for rollbacks
  //the second parameter is set to 0 which means remove since this was an insertion, the rollback stored is remove
  DatabaseOperations<Student> *studentOperation = new DatabaseOperations<Student>(true,0,newStudent);
  DatabaseOperations<Faculty> *facultyOperation = new DatabaseOperations<Faculty>(false,0,fac);
  studentStack->push(*(studentOperation));
  facultyStack->push(*(facultyOperation));
  rollbackCount = 0;
}

//8.
/*
Function: deleteStudent()
Return: none
Parameters: none
Exceptions: none
*/
/*prompts for a valid student ID number, if the student exists, it will delete them
but before it deletes the student from the database, it creates new DatabaseOperations for
student deletion and pushes it on the stacks, and creates a dummy faculty operation for
the facultyStack. It also checks the student's Advisor ID, and if
the faculty member exists, it removes the students ID from their list of Advisees
*/
void Simulation::deleteStudent(){
  int studentID = -1;
  while ((studentID < 1000000) || (studentID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID number of the student you wish to delete: ";
    cin >> studentID;
  }
  Student *stu = new Student();
  stu->setStudentID(studentID);
  if (studentDB->contains(stu)){
    //this part adds an operation to both stacks, and the first parameter is a bool which indicates which operation is valid
    //these are to ensure the student and faculty stacks work as one and are on the same level for rollbacks
    //the second parameter is set to 1 which means insert since this was an deletion, the rollback stored is insert
    Faculty *dummyFaculty = new Faculty();
    DatabaseOperations<Student> *studentOperation = new DatabaseOperations<Student>(true,1,studentDB->find(stu));
    DatabaseOperations<Faculty> *facultyOperation = new DatabaseOperations<Faculty>(false,1,dummyFaculty);
    studentStack->push(*(studentOperation));
    facultyStack->push(*(facultyOperation));
    rollbackCount = 0;

    int advID = studentDB->find(stu)->getAdvisorID();
    Faculty *fac = new Faculty();
    fac->setFacultyID(advID);
    if (facultyDB->contains(fac)){
      facultyDB->find(fac)->removeStudent(studentID);
      studentDB->deleteNode(stu);
    }
    else {
      cout << "Sorry Student could not be deleted because their Advisor does not exist" << endl;
      studentStack->pop();
      facultyStack->pop();
    }
  }
  else {
    cout << "Sorry, cannot delete because that Student ID does not match any Student in the Database!" << endl;
    return;
  }
}

//9.
/*
Function: addFaculty()
Return: none
Parameters: none
Exceptions: none
*/
/*prompts for valid entries of the required faculty info (ID,name,level,department)
If all the info is valid, it will create the faculty and add them to the
faculty database. It also is creating a database operation containing the faculty's info and
pushing it onto the facultyStack behind the scenes. It also makes a dummy student operation to push onto the studentStack
*/
void Simulation::addFaculty(){
  int newID = -1;
  while ((newID < 1000000) || (newID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID for the new Faculty: ";
    cin >> newID;
  }

  string newName = "";
  string first = "\0";
  string last = "\0";
  while (first == "\0" || last == "\0" || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the first name for the new Faculty: ";
    cin >> first;
    cout << "Enter the last name for the new Faculty: ";
    cin >> last;
  }
  newName = first + " " + last;

  string newLevel = "\0";
  while (newLevel == "\0" || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the level for the new Faculty: ";
    cin >> newLevel;
  }

  string newDepartment = "\0";
  while (newDepartment == "\0" || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the deparment for the new Faculty: ";
    cin >> newDepartment;
  }
  cout << "Faculty: " << newID << " | " << newName << " | " << newLevel << " | " << newDepartment << endl;
  Faculty *newFaculty = new Faculty(newID, newName, newLevel, newDepartment);
  facultyDB->insert(newFaculty);
  //this part adds an operation to both stacks, and the first parameter is a bool which indicates which operation is valid
  //these are to ensure the student and faculty stacks work as one and are on the same level for rollbacks
  //the second parameter is set to 0 which means remove since this was an insertion, the rollback stored is remove
  Student *dummyStudent = new Student();
  DatabaseOperations<Student> *studentOperation = new DatabaseOperations<Student>(false,0,dummyStudent);
  DatabaseOperations<Faculty> *facultyOperation = new DatabaseOperations<Faculty>(true,0,newFaculty);
  studentStack->push(*(studentOperation));
  facultyStack->push(*(facultyOperation));
  rollbackCount = 0;
}

//10.
/*
Function: deleteFaculty()
Return: none
Parameters: none
Exceptions: none
*/
/*prompts for a valid faculty ID number, if the faculty exists, it will delete them.
but before it deletes the faculty from the database, it creates new DatabaseOperations for
faculty deletion and pushes it on the stack, and creates a dummy student operation for
the studentStack. It also prompts for a new Advisor ID to set as the new Advisor for the
Advisees who just got their advisor removed. If the ADvisorID is valid, it removes all the
students from the old Advisor's list and adds them to the new advisor's list
*/
void Simulation::deleteFaculty(){
  int facultyID = -1;
  while ((facultyID < 1000000) || (facultyID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID number of the faculty member you wish to delete: ";
    cin >> facultyID;
  }
  Faculty *fac = new Faculty();
  fac->setFacultyID(facultyID);
  if (facultyDB->contains(fac)){
    //this part adds an operation to both stacks, and the first parameter is a bool which indicates which operation is valid
    //these are to ensure the student and faculty stacks work as one and are on the same level for rollbacks
    //the second parameter is set to 1 which means insert since this was an deletion, the rollback stored is insert
    Student *dummyStudent = new Student();
    DatabaseOperations<Student> *studentOperation = new DatabaseOperations<Student>(false,1,dummyStudent);
    DatabaseOperations<Faculty> *facultyOperation = new DatabaseOperations<Faculty>(true,1,facultyDB->find(fac));
    studentStack->push(*(studentOperation));
    facultyStack->push(*(facultyOperation));
    rollbackCount = 0;

    int newAdvID;
    cout << "Enter 7 digit ID number for the new advisors to this faculty member's students" << endl;
    cin >> newAdvID;
    Faculty *newFac = new Faculty();
    newFac->setFacultyID(newAdvID);
    if (facultyDB->contains(newFac)){
      Student *tempStu = new Student();
      while (!(facultyDB->find(fac)->mStudentIDList->isEmpty())){
        int id;
        id = facultyDB->find(fac)->mStudentIDList->removeFront();
        facultyDB->find(newFac)->AddStudent(id);
        tempStu->setStudentID(id);
        studentDB->find(tempStu)->setAdvisorID(newAdvID);
      }
      facultyDB->deleteNode(fac);
    }
    else {
      cout << "Sorry that new Advisor ID does not match any Faculty member in the database" << endl;
      studentStack->pop();
      facultyStack->pop();
      return;
    }

  }
  else {
    cout << "Sorry, cannot delete because that Faculty ID does not match any Faculty in the Database!" << endl;
    return;
  }
}

//11.
/*
Function: changeAdvisor()
Return: none
Parameters: none
Exceptions: none
*/
/*prompts for a valid student ID number, if the student exists, it will continue
then it prompts for a valid Advisor ID number. if the faculty exists in the database
it will remove the student from the old advisor's list, then add them to the new
advisor's list, and change the student's advisorID
*/
void Simulation::changeAdvisor(){
  int studentID = -1;
  while ((studentID < 1000000) || (studentID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID number of the student who needs their advisor changed: ";
    cin >> studentID;
  }
  Student *stu = new Student();
  stu->setStudentID(studentID);
  if (studentDB->contains(stu)){
    int facultyID = -1;
    while ((facultyID < 1000000) || (facultyID > 9999999) || cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Enter the 7 digit ID number of the new advisor: ";
      cin >> facultyID;
    }
    Faculty *newFac = new Faculty();
    newFac->setFacultyID(facultyID);
    if (facultyDB->contains(newFac)){
      Faculty *oldFac = new Faculty();
      oldFac->setFacultyID(studentDB->find(stu)->getAdvisorID());
      if (facultyDB->contains(oldFac)){
        facultyDB->find(oldFac)->removeStudent(studentID);
      }
      facultyDB->find(newFac)->AddStudent(studentID);
      studentDB->find(stu)->setAdvisorID(facultyID);
    }
    else {
      cout << "Sorry, cannot change to this advisor because that Faculty ID does not match any Faculty in the Database!" << endl;
      return;
    }
  }
  else {
    cout << "Sorry, cannot change advisor because that Student ID does not match any Student in the Database!" << endl;
    return;
  }
}

//12.
/*
Function: removeAdvisee()
Return: none
Parameters: none
Exceptions: none
*/
/*
prompts for a valid falculty ID, if the faculty exists, it will ask for the student ID they want to remove,
if the StudentID is valid in the database it will try to remove it from the faculty's list of advisees.
If you try to remove a Student from an Faculty's list who is not their advisor, their is a try-catch block that
will display a message that you tried to do that and there was an Error. If all goes well, it will remove the Student
from the Faculty's list of ADvisees, then prompt for another Faculty's ID to be the students new advisor. If the faculty
exists in the database, it will add the student to their list of advisees, and change the Student's ADvisorID
*/
void Simulation::removeAdvisee(){
  int facultyID = -1;
  Faculty *fac = new Faculty();
  Student *stu = new Student();
  while ((facultyID < 1000000) || (facultyID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout << "Enter the 7 digit ID number of the faculty member you wish to edit: ";
  cin >> facultyID;
  fac->setFacultyID(facultyID);
  if (!(facultyDB->contains(fac))){
    cout << "Sorry, that Faculty ID does not match any Faculty in the Database!" << endl;
    cout << "Please use a valid Faculty ID in order to remove a Student" << endl;
    return;
  }
  fac = facultyDB->find(fac);
}
  int studentID = -1;
  while ((studentID < 1000000) || (studentID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout << "Enter the 7 digit ID number of the advisee you wish to remove: ";
  cin >> studentID;
  stu->setStudentID(studentID);
  if (!(studentDB->contains(stu))){
    cout << "Sorry, that Student ID does not match any student in the Database!" << endl;
    cout << "Please use a valid student ID in order to remove a new Student" << endl;
    return;
  }
}
  try{
    fac->removeStudent(studentID);
  }
  catch(runtime_error){
    cout << "Error! Tried to remove a Student from a Faculty's list who wasn't the Student's Advisor!" << endl;
  }

  stu = studentDB->find(stu);
  int newAdvisorID = -1;
  while ((newAdvisorID < 1000000) || (newAdvisorID > 9999999) || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter the 7 digit ID of the advisor for the new Student: ";
    cin >> newAdvisorID;
    if (!(facultyDB->contains(fac))){
      cout << "Sorry, that Faculty ID does not match any Faculty in the Database!" << endl;
      cout << "Please use a valid Faculty ID in order to assign a new advisor for Student" << endl;
      return;
    }
  }
  stu->setAdvisorID(newAdvisorID);
  Faculty *fac2 = new Faculty();
  fac2->setFacultyID(newAdvisorID);
  facultyDB->find(fac2)->AddStudent(studentID);
}

//13.
/*
Function: rollback()
Return: none
Parameters: none
Exceptions: none
*/
/*
This is for un-doing any insertion / deletion actions while in the program changing the
database. The stacks of operations are new everytime the program begins, so you cannot rollback
an action from a previous run of the program. So it first checks if the stacks are empty, because if so
there is nothing to undo. It then checks if the rollbackCounter is at or above 5, becuase you can only
rollback 5 times continously, so it will not allow you to do more than that. If a rollback is available, it
will peek the studentStack to see if the studentOperation is the valid operation, if true, we know its a student
operation, if false it is a faculty operation. From there the function is pretty much the same for both student
and faculty. It checks the int value of the operation which shows what the operation is (0=remove,1=add). If it's
a remove, it gets the ID of the student/faculty, then removes them from the database. If its  add, it uses the
operation object to get all the info required to add a student/faculty, then adds them to the database. At the end,
if the rollback was successful, the rollback counter is incremented
*/
void Simulation::rollback(){
  if (studentStack->isEmpty() && facultyStack->isEmpty()){
    cout << "Rollback stack is empty, there are no actions to undo!" << endl;
    return;
  }
  if (rollbackCount >= 5){
    cout << "Sorry, you are only able to rollback 5 times continously." << endl;
    return;
  }

  bool isStudentRealOperation = studentStack->peek().isRealOperation();
  if (isStudentRealOperation){
    //student is real operation
    facultyStack->pop();
    int action = studentStack->peek().getAction();
    if (action == 0){
      int studentID = studentStack->pop().getObject()->getID();
      Student *stu = new Student();
      stu->setStudentID(studentID);
      if (studentDB->contains(stu)){
        int advID = studentDB->find(stu)->getAdvisorID();
        Faculty *fac = new Faculty();
        fac->setFacultyID(advID);
        //this removes the student from the faculty list before deleting
        facultyDB->find(fac)->removeStudent(studentID);
        studentDB->deleteNode(stu);
        cout << "ROLLBACK SUCCESSFUL: Student deleted." << endl;
      }
      else {
        cout << "Sorry, cannot rollback and delete because that Student ID no longer matches any Student in the Database!" << endl;
        return;
      }
    }
    else if (action == 1){
      int studentID = studentStack->peek().getObject()->getID();
      string name = studentStack->peek().getObject()->getName();
      string level = studentStack->peek().getObject()->getLevel();
      string major = studentStack->peek().getObject()->getStudentMajor();
      double studentGPA = studentStack->peek().getObject()->getStudentGPA();
      int advisorID = studentStack->pop().getObject()->getAdvisorID();
      Student* stu = new Student(studentID, name, level, major, studentGPA, advisorID);
      studentDB->insert(stu);
      cout << "ROLLBACK SUCCESSFUL: Student added." << endl;
      Faculty *fac = new Faculty();
      fac->setFacultyID(advisorID);
      if (facultyDB->contains(fac)){
        //if the facultyID is valid, it adds the student to their list
        facultyDB->find(fac)->AddStudent(studentID);
      }
      else {
        cout << "Could not add Student to Advisor List because that Advisor is not in the database!" << endl;
      }
    }
    else {
      throw runtime_error("Rollback action doesn't exist!");
    }
  }
  else{
    //faculty is real operation
    studentStack->pop();
    int action = facultyStack->peek().getAction();
    if (action == 0){
      int facultyID = facultyStack->pop().getObject()->getID();
      Faculty *fac = new Faculty();
      fac->setFacultyID(facultyID);
      if (facultyDB->contains(fac)){
        facultyDB->deleteNode(fac);
        cout << "ROLLBACK SUCCESSFUL: Faculty deleted." << endl;
      }
      else {
        cout << "Sorry, cannot rollback and delete because that Student ID no longer matches any Student in the Database!" << endl;
        return;
      }
    }
    else if (action == 1){
      int facultyID = facultyStack->peek().getObject()->getID();
      string name = facultyStack->peek().getObject()->getName();
      string level = facultyStack->peek().getObject()->getLevel();
      string department = facultyStack->pop().getObject()->getFacultyDepartment();
      Faculty* fac = new Faculty(facultyID, name, level, department);
      facultyDB->insert(fac);
      cout << "ROLLBACK SUCCESSFUL: Faculty added." << endl;
    }
    else {
      throw runtime_error("Rollback action doesn't exist!");
    }
  }

  ++rollbackCount;
}

//14.
/*
Function: removeAdvisee()
Return: none
Parameters: none
Exceptions: none
*/
//this will save the student and faculty databases to the files, and close the files then exit
void Simulation::exitAndSave(){
  ifstream facultyInput;
  facultyInput.open("facultyTable.txt", ofstream::out | ofstream::trunc);
  ifstream studentInput;
  studentInput.open("studentTable.txt", ofstream::out | ofstream::trunc);
  facultyDB->treeToString("facultyTable.txt");
  studentDB->treeToString("studentTable.txt");
  facultyInput.close();
  studentInput.close();
}

/*
Function: fileProcessor()
Return: none
Parameters: none
Exceptions: none
*/
/*starts the process by reading the file if it is there, and writing it to the database/BST
it goes through the lines of each file and parses the text because the files are stored as
CSV (comma separated values), it stores the info from the file in the correct variables, then
creates a new Student/Faculty and inserts them into the respective database. At the end it
closes the two files, then if the files were processed it returns true, and if there were
no files to process it returns false
*/
bool Simulation::fileProcessor(){
  // return false;
  string studentArray[6];
  string facultyArray[5];
  //if file successfully opens, need to read binary file and
  // re-create databases
  ifstream facultyInput;
  facultyInput.open("facultyTable.txt");
  ifstream studentInput;
  studentInput.open("studentTable.txt");

  if (facultyInput.is_open() && studentInput.is_open()){
    // cout << "Files found" << endl;
    //read files and create trees
    string str;
    int k = 0;
    while(getline(studentInput,str)){
      k = 0;
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
          // cout << s << endl;
          s = "";
          ++k;
        }
        studentArray[5] = s;
      }
      stuID = stoi(studentArray[0]);
      stuName = studentArray[1];
      year = studentArray[2];
      stuMajor = studentArray[3];
      stuGPA = stod(studentArray[4]);
      advisorID = stoi(studentArray[5]);
      Student *newStudent = new Student(stuID, stuName, year, stuMajor, stuGPA, advisorID);
      // cout << newStudent->toString() << endl;
      studentDB->insert(newStudent);
      // cout << "Student inserted" << endl;
    }
    // cout << "Done with students" << endl;
    while(getline(facultyInput,str)){
      k = 0;
      int facID = 0;
      string facName = "";
      string job = "";
      string facDepartment = "";
      string s;
      // cout << str.size() << endl;
      for (int i = 0; i < str.size(); ++i){
        // cout << k << endl;
        if (k < 4){
        if (str[i] != ','){
          // cout << str[i] << endl;
          s += str[i];
        } else {
          // cout << s << endl;
          facultyArray[k] = s;
          ++k;
          s = "";
        }
      } else {
        s += str[i];
        // cout << "in student list: " << s << endl;
    }}
      facultyArray[4] = s;
      // cout << "before fac ID" << endl;
      // cout << facultyArray[0] << endl;
      facID = stoi(facultyArray[0]);
      facName = facultyArray[1];
      job = facultyArray[2];
      facDepartment = facultyArray[3];
      Faculty *newFaculty = new Faculty(facID, facName, job, facDepartment);
      string temp;
      int tempID;
      for (int i = 1; i < s.size() - 1; ++i){
        // cout << "in list for loop" << endl;
        if (s[i] != ','){
          temp += s[i];
        } else {
        tempID = stoi(temp);
        newFaculty->AddStudent(tempID);
        temp = "";
      }
      }
      facultyDB->insert(newFaculty);
      // cout << "faculty inserted" << endl;
    }


    // cout << facultyDB->treeToString();
    // cout << studentDB->treeToString();
    facultyInput.close();
    studentInput.close();

    return true;
  }
  else {
    return false;
  }
}
