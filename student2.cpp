#include <iostream>
#include <cstring>
class student
{
public:
  int age;
  char *name;
  student(int age, char *name)
  {
    this->age = age;
    // this->name = name; //it is shallow copy
    //deep copy.
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }
  //copy constructor do shallow copy that's why we need creat copy constructor.
  student(student const &s)
  {
    this->age = s.age;
   // this->name=name;
    this->name = new char[strlen(s.name) + 1];
    strcpy(this->name, s.name);
  }
  void display()
  {
    cout << name << " " << age << endl;
  }
};