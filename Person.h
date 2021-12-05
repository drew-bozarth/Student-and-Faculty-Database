#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class Person{
public:
  Person();
  Person(int i, string n, string l){
    id = i;
    name = n;
    level = l;
  };
  virtual ~Person(){};
  int id;
  string name;
  string level;
  virtual int getID(){
    return id;
  };
  virtual string getName(){
    return name;
  };
  virtual string getLevel(){
    return level;
  };
  virtual void toString(){
    cout << "Name: " << name;
    cout << " | ID number: " << id;
    cout << " | level: " << level;
  }
}


#endif
