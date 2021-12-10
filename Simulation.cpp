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
  studentStack = new GenStack<DatabaseOperations<Student>>();
  facultyStack = new GenStack<DatabaseOperations<Faculty>>();
  rollbackCount = 0;
}

Simulation::~Simulation(){
  //destructor
  delete studentDB;
  delete facultyDB;
  delete studentStack;
  delete facultyStack;
}

void Simulation::start(){
  bool fileProcessed = fileProcessor();
  if (!fileProcessed){
    cout << "No file found, blank databases created" << endl;
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

  DatabaseOperations<Student> *studentOperation = new DatabaseOperations<Student>(true,0,newStudent);
  DatabaseOperations<Faculty> *facultyOperation = new DatabaseOperations<Faculty>(false,0,fac);
  studentStack->push(*(studentOperation));
  facultyStack->push(*(facultyOperation));
  rollbackCount = 0;
}

//8.
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

  Student *dummyStudent = new Student();
  DatabaseOperations<Student> *studentOperation = new DatabaseOperations<Student>(false,0,dummyStudent);
  DatabaseOperations<Faculty> *facultyOperation = new DatabaseOperations<Faculty>(true,0,newFaculty);
  studentStack->push(*(studentOperation));
  facultyStack->push(*(facultyOperation));
  rollbackCount = 0;
}

//10.
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
  fac->removeStudent(studentID);
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
void Simulation::rollback(){
  if (studentStack->isEmpty() && facultyStack->isEmpty()){
    cout << "Stack is empty, there are no actions to undo!" << endl;
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

//starts the process by reading the file if it is there, and writing it to the database/BST
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
