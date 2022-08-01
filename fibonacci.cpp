#include <iostream>
using namespace std;
int fibonacci(int n)
{

    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main()
{
    int n;
    int i;
    cout << "Enter a index to get fibonacci number: ";
    cin >> n;
    cout << fibonacci(n) << endl;
    cout << "1 to n fibonacci serise i:" << endl;
    for (i = 1; i <= n; i++)
    {
        //cout<<"1 to n fibonacci serise i:"<<endl;
        cout << fibonacci(i);
        cout << endl;
    }
}