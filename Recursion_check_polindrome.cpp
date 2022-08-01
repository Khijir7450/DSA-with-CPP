#include <iostream>
using namespace std;
bool checkPolindrome(char arr[], int i, int j)
{
    if (i >= j)
    {
        return true;
    }
    if (arr[i] == arr[j])
    {
        return checkPolindrome(arr, i + 1, j - 1);
    }
    else
        return false;
}
int main()
{
    int n;
    cout << "Enter size of string:" << endl;
    cin >> n;
    char arr[100];
    cout << "Enter a char array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Your array is:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    int i = 0;
    int j = n - 1;
    if (checkPolindrome(arr, i, j))
    {
        cout << endl
             << "polindrome";
    }
    else
        cout << endl
             << "not";

    return 0;
}