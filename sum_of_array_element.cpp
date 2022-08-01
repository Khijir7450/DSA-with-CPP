#include <iostream>
using namespace std;
int SumOfArray(int a[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    else if (size == 1)
    {
        return a[size-1];
    }
    else{
    int sum = 0;
     return sum=sum+a[size-1]+SumOfArray(a,size-1);
    }
}
int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int *p = new int[n];
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "Sum of array element is:";
    cout << SumOfArray(p, n);
    delete []p;
    return 0;
}