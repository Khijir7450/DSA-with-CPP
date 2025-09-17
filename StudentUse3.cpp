#include <iostream>
using namespace std;
#include "student.cpp"
int main()
{
    student s1;         //Default constructor called.
    student s2(20);     //paramiterise(1) constructor called.
    student s3(20,100); //paramiterise(2) constructor called.
    student s4(s3);     //copy constructor called.
    s4=s3;              //copy asignment operator.
    student s6=s2;      //copy constructor called.its actually student s6(s2);
 return 0;
}