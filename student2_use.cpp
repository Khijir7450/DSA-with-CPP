#include <iostream>
using namespace std;
#include "student2.cpp"
int main()
{
    char name[] = "abcd";
    student s1(20, name);
    s1.display();
    name[0] = 'x';
    student s2(21, name);
    student s3(s1);   //copy constructor do shallow copy.
    s1.display();   //so s1.name print 'zbcd'
    s3.name[0] = 'z';
    s2.display();
    s3.display();
    student s4(s3);
    s4.name[3]='z';
    s4.display();

    return 0;
}