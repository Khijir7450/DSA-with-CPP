#include <iostream>
using namespace std;
int XtoThePower(int x, int n)
{
    if (n == 1)
    {
        return x;
    }
    int num = x * XtoThePower(x, (n - 1));
    return num;
}
int main()
{
    int x, n;
    cout << "Enter the base(x):";
    cin >> x;
    cout <<endl<< "Enter the power(n):";
    cin >> n;
    cout << "x^n is=" << XtoThePower(x, n);
    return 0;
}