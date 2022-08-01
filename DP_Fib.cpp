#include <iostream>
using namespace std;
//dp
int fibonacci(int n, int *arr)
{

    if (n == 1 || n == 0)
    {
        arr[n] = 1;
        return 1;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    int ans = fibonacci(n - 1, arr) + fibonacci(n - 2, arr);
    arr[n] = ans;
    return ans;
}
//Memoization
int fibM(int n){
    int* arr=new int[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int *fib = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        fib[i] = -1;
    }

    cout << fibonacci(n, fib) << endl;
    cout<<"memo:"<<fibM(n);

    // cout << "1 to n fibonacci serise i:" << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     //cout<<"1 to n fibonacci serise i:"<<endl;
    //     cout << fibonacci(i);
    //     cout << endl;
    // }
}