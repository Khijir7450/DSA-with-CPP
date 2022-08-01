#include <iostream>
using namespace std;
int main()
{
   /*  int *p = new int;
    *p = 10;
    cout << *p << endl;
    (*p)++;
    cout << *p << endl;
    cout<<p<<endl;
    delete p;
    *p=18;
    cout<<*p<<endl;
    cout<<p<<endl;
    delete p; */
  int n;
    cout << "enter size off array:";
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
    delete[] p;

    //max in array
    /* int max=-1000;
    for (int i = 0; i < n; i++)
    {
        if (p[i]>max)
        {
            max=p[i];
        }
    }
    cout<<endl<<"Maximum number of your array is:"<<max;
    */

    return 0;
}