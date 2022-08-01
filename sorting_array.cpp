#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of array:";
    cin >> n;
    int a[50];
    cout << "Enetr the input of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "you entered:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

    //array in descending order
     for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    cout<<"array in descending order:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<' ';
    }
    //ascending order
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    cout<<end;
    cout << "array in ascending order:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}