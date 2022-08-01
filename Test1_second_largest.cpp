#include <iostream>
using namespace std;
int main()
{
    int arr[100];
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Your array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int l1 = -999;
    int l2 = -999; //l1 for largest and l2 for 2nd largest.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > l1)
        {
            l2 = l1;
            l1 = arr[i];
        }
        else if (arr[i] > l2)
        {
            l2 = arr[i];
        }
    }
    cout << "largest number of the array is:" << l1 << endl;
    cout << "2nd largest number of the array is:" << l2 << endl;
}