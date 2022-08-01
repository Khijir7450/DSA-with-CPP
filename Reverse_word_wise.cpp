#include <iostream>
#include <cstring>
using namespace std;
void reverseString(char s[], int si, int ei)
{
    int i = si;
    int j = ei;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
        i++;
    }
}

void stringReverseWardWise(char s[])
{
    int e = strlen(s) - 1;
    reverseString(s, 0, e);
    int si = 0;
    int ei = 0;
    int i;
    for (i = 0; i < strlen(s) - 1; i++)
    {
        if ( s[i] == ' ')
        {
            ei = i - 1;
            reverseString(s, si, ei);
            si = i + 1;
            ei = i + 1;
        }

    }
    ei=i;
    reverseString(s,si,ei);
}
int main()
{
    char s[100];
    cout << "Enter string:";
    cin.getline(s, 100);
    int len = strlen(s);
    cout << "Your string is: " << s << endl;
    stringReverseWardWise(s);
    cout << "After reverse word wise:" << endl;
    cout << s;
}
/*
int j = len - 1;
for (int i = 0; i < j; i++)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    j--;
}
cout << s << endl;
int si = 0;
//int endindex = 0;
strcat(s, " ");
cout << "after reverse:" << endl;
for (int i = 0; i < len; i++)
{
    if (s[i] == ' ' && s[i + 1] != ' ')
    {
        for (int j = i; j >= si; j--)
        {
            cout << s[j];
        }
        si = i + 1;
    }
    /* else
        continue;

    while (si < endindex)
    {
        char temp = s[si];
        s[si] = s[endindex];
        s[endindex] = temp;
        si++;
        endindex--;
    }
    si = endindex + 1;
*/
