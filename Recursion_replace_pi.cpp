#include <iostream>
#include <cstring>
using namespace std;
void ReplacePi(char s[], int size)
{
    if (size <= 1)
    {
        return;
    }
    if (s[0] == 'p')
    {
        if (s[1] == 'i')
        {
            for (int i = strlen(s) + 2; i > 2; i--)
            {
                s[i] = s[i - 2];
            }
            s[0] = '3';
            s[1] = '.';
            s[2] = '1';
            s[3] = '4';
            ReplacePi(s + 2, strlen(s));
        }
        else
        ReplacePi(s+1,strlen(s));
    }
    else
    {
        ReplacePi(s+1,strlen(s));
    }
}
int main()
{
    char str[100];
    cout << "Enter a string:";
    cin >> str;
    int len = strlen(str);
    ReplacePi(str,len);
    cout<<str;

    return 0;
}