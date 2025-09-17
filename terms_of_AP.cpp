//Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter how many terms you want to print:";
    cin >> x;
    cout << "Your 3N+2 AP serise is:" << endl;
    for (int i = 1; i <= x; i++)
    {
        if ((3 * i + 2) % 4 == 0)
        {
            x=x+1;
            continue;
        }
        else
        {
            cout << (3 * i + 2) << " ";
        }
    }
}