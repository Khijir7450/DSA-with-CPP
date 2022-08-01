#include <iostream>
using namespace std;
#include "student.cpp"
int main()
{
    student s1(20, 100);
    // s1.age = 20;
    //s1.setRoll(200);
    s1.Display();
    student *s2 = new student(21, 101);
    // s2->age=21;
    s2->setRoll(201);
    s2->Display();
    student s3(23);
    s3.setRoll(103);
    s3.Display();
    student *s4 = new student(24);
    s4->setRoll(104);
    s4->Display();
    delete s2;
    delete s4;

    return 0;
}