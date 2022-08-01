#include <iostream>
#include <cstring>
using namespace std;
void trimString(char arr[])
{
    int n = strlen(arr);
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] != ' ')
        {
            cout << arr[i];
        }
      /*  else  //if i want to change the line where is space;
        {
            cout<<endl;
        }*/
    }
}
int main()
{
    char arr[100];
    cout << "Enter a string:";
    cin.getline(arr, 100);
    cout << "string after trim space:" << endl;
    trimString(arr);
}