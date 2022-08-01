#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter a number which factorial you want:";
    cin >> n;
    cout << fact(n);
}