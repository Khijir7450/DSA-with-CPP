#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int arr[100];
    cout << "Enter the array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "You entered:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout<<endl;
    int d;
    cout << "Enter how many time u want to rotate:";
    cin >> d;
    cout<<"array after rotation:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[(i+d)%n]<<' ';
    }
    
    /*int temp;
    for (int i = 0; i < d; i++)
    {
        for (int i = 0; i < (n - 1); i++)
        {
            int temp = arr[0];
            arr[i] = arr[i + 1];
            arr[n - 1] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }*/
}