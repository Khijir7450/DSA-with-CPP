#include <iostream>
#include <cstring>
using namespace std;
#include "student1.cpp"
int main()
{
    string name;
    cout << "enter name of the student:" << endl;
    getline(cin, name);
    student s1(20, name);
    s1.display();
    student s2(s1);
    s2.name="asif bichi";
    s2.age = 25;
    s1.display();
    s2.display();
    return 0;
}