#include <bits/stdc++.h>
using namespace std;
//recursive sol
int CountWay(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 4;
    }
    else
    {
        return CountWay(n - 1) + CountWay(n - 2) + CountWay(n - 3);
    }
}
//memoization dp
int CountWay(int n, int *dp)
{
    if (n == 0)
    {
        return dp[n];
    }
    if (n == 1)
    {
        return dp[n];
    }
    if (n == 2)
    {
        return dp[n];
    }
    if (n == 3)
    {
        return dp[n];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = CountWay(n - 1) + CountWay(n - 2) + CountWay(n - 3);
        return dp[n];
    }
}
//Itretive dp
int CountWayI(int n){
    int* arr=new int[n+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    int ans= arr[n];
    delete [] arr;
    return ans;
}
int main()
{
    int n;
    cout << "Enter number of stair:" << endl;
    cin >> n;
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cout << "Number of way: " << CountWay(n) << endl;
    cout << "Number of way using recursive dp: " << CountWay(n, dp)<<endl;
    cout << "Number of way using Itretive dp: " << CountWayI(n);
}