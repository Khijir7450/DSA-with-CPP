#include <iostream>
using namespace std;
void RotationArray(int a[], int n, int d)
{
    for (int j = 0; j < d; j++)
    {

        int temp = a[0];
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[100];
    int n;
    cout << "Enter size of array:";
    cin >> n;
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "your array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    int d;
    cout << "Enter how many time you want to rotate:";
    cin >> d;
    cout << "Array after rotation:" << endl;
    RotationArray(a, n, d);
}