#include <iostream>
using namespace std;
void ReplaceX1ByX2(char s[], char x1, char x2)
{
    if (s[0] == '\0')
    {
        return;
    }
    if (s[0] == x1)
    {
        s[0] = x2;
        ReplaceX1ByX2(s+1,x1,x2);
    }
    else
    {
        ReplaceX1ByX2(s + 1,x1,x2);
    }
}
int main()
{
    char str[100];
    char c1, c2;
    cout << "Enter a string:";
    cin >> str;
    cout << "Enter which charecter(c1) you want to replace:" << endl;
    cin >> c1;
    cout << "Enter,c1 replace by what charecter:" << endl;
    cin >> c2;
    ReplaceX1ByX2(str, c1, c2);
    cout << str;

    return 0;
}