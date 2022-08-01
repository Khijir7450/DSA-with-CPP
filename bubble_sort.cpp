#include <iostream>
using namespace std;
//function defination and declearation
//function for sorting array and print sorted array
void bubbleSort(int arr[], int n)
{
    //sorting array
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)//  i<n-1 issme koiii dikkat nehi hoga
        {                                  //  par i<n-1-j is batter logic
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    //print sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int arr[n];
    cout << "Enter array element:" << endl; //input array element
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //print array which entered by user
    cout << "You entered array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "array after sorting:" << endl;
    bubbleSort(arr, n);
}