#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    int ans = 0;
    int pv = 1;
    while (n > 0)
    {
        int r = n % 10;
        ans = (ans * 10) + r;
        n = n / 10;
    }
    cout << "Reverse of the number is:" << ans;
    return 0;
}