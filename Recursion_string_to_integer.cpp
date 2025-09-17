#include <iostream>
using namespace std;
void reverse(int p[], int size)
{
    int j = size - 1;
    for (int i = 0; i <= j; i++)
    {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        j--;
    }
}
int StrToInteger(int p[], int size,int pv)
{

    if (size == 0)
    {
        return 0;
    }
    int val =(p[0] * pv)+StrToInteger(p+1,size-1,pv*10);
    return val;
}
int main()
{
    int pv=1;
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int *p = new int[n];
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "Your array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    reverse(p, n);
    cout<<endl<<StrToInteger(p,n,pv);

    delete[] p;

    return 0;
}