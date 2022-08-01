#include <iostream>
using namespace std;
void RotateArray(int arr[], int n)
{

    int j = n - 1;
    int temp;
    for (int i = 0; i < j; i++)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}
int main()
{
    int arr[100];
    int n;
    cout << "Enter size of array:";
    cin >> n;
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "array after rotation:" << endl;
    RotateArray(arr, n);
}