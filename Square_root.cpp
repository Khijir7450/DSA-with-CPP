#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    int i = 1;
    while (i * i <= n)
    {
        if (i * i == n)
        {
            cout << "square root is:" << i;
            goto end;
        }
        i++;
    }
    cout << "square root is:" << i - 1;
end:1;
}