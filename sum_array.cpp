#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<<"you enter:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    //sum off array
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    cout << "sum of array is=" << sum;
}