/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - Persont.h */

//these are the header guards
#ifndef PERSON_H
#define PERSON_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
#include <string>
//standard namespace libaray in C++
using namespace std;

class Person{
public:
  Person(){};
  Person(int i, string n, string l){
    id = i;
    name = n;
    level = l;
  };
  virtual ~Person(){};
  int id;
  string name;
  string level;
  virtual int getID(){};
  virtual string getName(){};
  virtual string getLevel(){};
  virtual string toString(){};
  virtual string toFile(){};
};


#endif
