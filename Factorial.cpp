#include <iostream>
using namespace std;
int factorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    int fact = x * factorial(x - 1);
    return fact;
}
int main()
{
    int n;
    cout << "Enter a number which factorial you want:";
    cin >> n;
    int fact= factorial(n);
    cout<<"="<<fact;
    return 0;
}