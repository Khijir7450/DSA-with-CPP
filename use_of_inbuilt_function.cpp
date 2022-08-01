#include <iostream>
#include <cstring> //for using inbuilt function--- strlen(a)/strcmp(arr1,arr2)/strcpy(arr1,arr2);
using namespace std;
int main()
{
    char arr1[100], arr2[100];
    cout << "Enter a string:" << endl;
    cin.getline(arr1, 100);
    cout << "Enter another string:" << endl;
    cin.getline(arr2, 100);
    cout << "before copy your strings is:" << endl;
    cout << arr1 << endl;
    cout << arr2 << endl;
   /* strcpy(arr1, arr2);
    cout << "string after copy:" << endl;
    cout << "1st string:" << arr1 << endl;
    cout << "2nd string:" << arr2 << endl;*/
    strncpy(arr1, arr2, 3);  //for copy n element;
    cout << "string after copy 3 element:" << endl;
    cout << "1st string:" << arr1 << endl;
    cout << "2nd string:" << arr2 << endl;

    /*
    //use of strcmp(arr1,arr2)
    char arr1[100], arr2[100];
    cout << "Enter a string:" << endl;
    cin.getline(arr1, 100);
    cout << "Enter another string:" << endl;
    cin.getline(arr2, 100);
   // cout << "if those string are same then we return 0,else non-zero number" << endl;
   // cout << strcmp(arr1, arr2);
    if (strcmp(arr1,arr2)==0)
    {
        cout<<"Those string are same."<<endl;
    }
    else
    {
        cout<<"Those string not same."<<endl;
    }*/

    /* char a[100];
    //use of strlen(arr)
    cout << "enter something(like your name): ";
    cin.getline(a, 100);
    cout << "your string is:" << endl;
    cout << a<<endl;
    int len = strlen(a);
    cout << "length of string is:" << len;
    */
}