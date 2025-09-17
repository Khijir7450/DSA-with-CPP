#include <iostream>
using namespace std;
int length(char a[]) //for find actual length of string; 
{
    int count = 0;
    for (int i = 0; a[i] != 0; i++)
    {
        count++;
    }
    return count;
}
void reverse(char a[])  //for reversing the string;
{
    int len = length(a);
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        char temp;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char a[100];
    cout << "Enter string:" << endl;
    cin.getline(a, 100); //dont use (cin>>).
    cout << "your sting is:" << endl;
    cout << a << endl;
    //cout << "length off the string is:" << length(a) << endl;
    cout << "string after reverse:" << endl;
    reverse(a); //reverse function call;
    cout << a;
}