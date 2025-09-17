#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[100];
    int len = strlen(s);
    cout << "Enter a string:" << endl;
    cin.getline(s, 100);
    cout << "Your string is:" << endl;
    cout << s << endl;
    char x1;
    cout << "Enter which charecter you want to replace:";
    cin >> x1;
    char x2;
    cout << endl
         << "Enter what charecter you want to put in string:";
    cin >> x2;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == x1)
        {
            s[i] = x2;
        }
    }
    cout << "after replace your string is:" << endl;
    cout << s;
}