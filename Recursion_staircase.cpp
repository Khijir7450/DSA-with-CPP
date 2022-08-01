#include <iostream>
using namespace std;
int CountWay(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }
    else
    {
        return CountWay(n - 1) + CountWay(n - 2) + CountWay(n - 3);
    }
}

int main()
{
    int n;
    cout << "Enter number of stair:";
    cin >> n;
    cout << CountWay(n);

    return 0;
}