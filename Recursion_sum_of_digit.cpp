#include <iostream>
using namespace std;
int SumOfDigit(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int sum = (n % 10) + SumOfDigit(n / 10);
    return sum;
}
int main()
{
    int n;
    cout << "Enter an integer:";
    cin >> n;
    cout << "sum of all digit of integer n,is =" << SumOfDigit(n);
    return 0;
}