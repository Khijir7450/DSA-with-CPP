#include <iostream>
using namespace std;
#include "student.cpp"
int main()
{
    student s1(20, 200);
    cout << "s1:";
    s1.Display();
    student s2(s1);
    cout << "s2:";
    s2.Display();
    student *s3 = new student(21, 201);
    cout << "s3:";
    s3->Display();
    student *s4 = new student(*s3);
    cout << "s4:";
    s4->Display();
    student s5(*s3);
    cout << "s5:";
    s5.Display();
    student *s6 = new student(s1);
    cout << "s6:";
    s6->Display();
    s5 = s1;
    cout << "s5:";
    s5.Display();
    cout << "s1:";
    s1.Display();
    s1=*s6;
    cout << "s6:";
    s3->Display();
    cout << "s1:";
    s1.Display();
    *s3=s1;
    cout << "s3:";
    s3->Display();
    cout << "s1:";
    s1.Display();
    delete s3;
    delete s4;
    delete s6;

    return 0;
}