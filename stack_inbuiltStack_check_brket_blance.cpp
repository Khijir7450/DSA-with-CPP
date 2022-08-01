#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
string checkBalance(string s)
{
    stack<char> s2;
    string result = "false";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            s2.push(s[i]);
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (s2.empty())
            {
                result = "false";
            }

            else if ((int)s2.top()==(int)s[i]-1  || (int)s2.top()==(int)s[i]-2)
            {
                result = "true";
                s2.pop();
            }
            else
            {
                result = "false";
                break;
            }
        }
    }
    if (s2.empty())
    {
        result = "true";
    }
    else
        result = "false";

    return result;
}

int main()
{
    string s;
    cout << "Enter Expression(brackets):" << endl;
    getline(cin, s);
    cout << checkBalance(s);
    return 0;
}