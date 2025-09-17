#include <iostream>
using namespace std;
int main()
{
    int basic;
    cout << "please Enter your basic salary:" << endl;
    cin >> basic;
    char grade;
    cout << "Enter your job grade(A/B/C):" << endl;
    cin >> grade;
    /* int allow;
    if (grade == 'A')
    {
        allow = 1700;
    }
    else if (grade == 'B')
    {
        allow = 1500;
    }
    else if (grade == 'C')
    {
        allow = 1300;
    }
    else
    {
        cout << "fuck u man,you dont enter a valid grade.";
    }*/
    float hra;
    hra = (20.0 / 100) * basic;
    float da;
    da = (50.0 / 100) * basic;
    float pf;
    pf = (11.0 / 100) * basic;
    int allow;
    //float totalsalary;
    //totalsalary = basic + allow + hra + da + pf;
    if (grade == 'A')
    {
        allow = 1700;
        float totalsalary;
        totalsalary = basic + allow + hra + da + pf;
        cout << totalsalary;
    }
    else if (grade == 'B')
    {
        allow = 1500;
        float totalsalary;
        totalsalary = basic + allow + hra + da + pf;
        cout << totalsalary;
    }
    else if (grade == 'C')
    {
        allow = 1300;
        float totalsalary;
        totalsalary = basic + allow + hra + da + pf;
        cout << totalsalary;
    }
    else
    {
        cout << "fuck u man,you dont enter a valid grade.";
    }
    /* float totalsalary;
    totalsalary = basic + allow + hra + da + pf;
    cout << totalsalary;*/
}