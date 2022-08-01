#include <iostream>
using namespace std;
void SumOFtwoArray(int a1[], int a2[], int n1, int n2)
{
    int carry = 0;
    int val;
    int i1 = n1 - 1;
    int i2 = n2 - 1;
    int n3 = max(n1, n2); //length of result array
    int a3[n3];           //result array.
    int i3 = n3 - 1;      //start value stored in result array form i3 index.

    while (i1 >= 0 || i2 >= 0)
    {

        int sum = carry;
        if (i1 >= 0) //-ve index are dose not exist,so if i1>=0 then added array1 in sum
        {            //(nehi too tumhara code gand majaki ho jayega)
            sum += a1[i1];
        }
        if (i2 >= 0) //upar dekho,same cause.
        {
            sum += a2[i2];
        }
        carry = sum / 10;
        val = sum % 10; //remainder will stored in result array.
        a3[i3] = val;
        i1--;
        i2--;
        i3--;
    }
    cout << "Sum of tow array is:" << endl;
    if (carry != 0) //at the end,if carry stored non-zero number then carry also print.
    {
        cout << carry << " ";
    }
    for (int i = 0; i < n3; i++) //for print result array.
    {
        cout << a3[i] << " ";
    }
}
int main()
{
    int a1[100], a2[100];
    int n1, n2;
    cout << "Enter the size of your 1st array:";
    cin >> n1;
    cout << "Enter the size of your 2nd array:";
    cin >> n2;
    cout << "Enter the 1st array element:" << endl;
    for (int i = 0; i < n1; i++) //input array 1 element.
    {
        cin >> a1[i];
    }
    cout << "Enter the 2nd array element:" << endl;
    for (int i = 0; i < n2; i++) //input array 2 element.
    {
        cin >> a2[i];
    }
    cout << "Your 1st array is:" << endl;
    for (int i = 0; i < n1; i++) //output array 1 element.
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    cout << "Your 2nd array is:" << endl;
    for (int i = 0; i < n2; i++) //output array 2 element.
    {
        cout << a2[i] << " ";
    }
    cout << endl;
    SumOFtwoArray(a1, a2, n1, n2); //function call.
}