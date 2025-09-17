#include <bits/stdc++.h>
using namespace std;
// Recursive sol
int minimunCount(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + minimunCount(n - i * i));
    }
    return ans;
}
// Memoization
int minSquares(int n, int *dp)
{

    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        int currAns;
        if (dp[n - (i * i)] == -1)
        {
            currAns = minSquares(n - (i * i), dp);
            dp[n - (i * i)] = currAns;
        }
        else
        {
            currAns = dp[n - (i * i)];
        }
        ans = min(currAns, ans);
    }
    return ans + 1;
}
int minSquares(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        arr[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            arr[i] = min(arr[i], arr[i - (j * j)]);
        }
        arr[i]+=1;

    }

    int ans = arr[n];
    delete[] arr;
    return ans;
}
int main()
{
    int n;
    cout << "Enter a Number:";
    cin >> n;
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    // cout<<"Recursion:"<<minimunCount(n)<<endl;
    cout << "Memoization: " << minSquares(n, dp) << endl;
    cout<<"Itretive: "<<minSquares(n)<<endl;
    delete[] dp;
}