#include <iostream>
#include <cstring>
using namespace std;
void PairStar(char s[], int size)
{
    if (size == 0)
    {
        return;
    }
    if (s[0] == s[1])
    {
        for (int i = strlen(s) + 1; i > 0; i--)
        {
            if (i == 1)
            {
                s[i] = '*';
            }
            else
                s[i] = s[i - 1];
        }
        PairStar(s + 2, strlen(s));
    }
    else
    {
        PairStar(s + 1, strlen(s));
    }
}
int main()
{
    char str[100];
    cout << "Enter a string:";
    cin >> str;
    int len = strlen(str);
    PairStar(str, len);
    cout << str;

    return 0;
}