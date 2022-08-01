#include <bits/stdc++.h>
using namespace std;

// Recursive sol
int MaxMoney(int *money, int n, int si)
{
    if (si >= n)
    {
        return 0;
    }
    int ans1 = MaxMoney(money, n, si + 1);
    int ans2 = money[si] + MaxMoney(money, n, si + 2);
    return max(ans1, ans2);
}
// Memoization
int maxMoney(int *money, int n, int si, int *dp)
{
    if (si >= n)
    {
        dp[n] = 0;
        return 0;
    }
    if (dp[si] != -1)
    {
        return dp[si];
    }
    else
    {
        int ans1 = maxMoney(money, n, si + 1, dp);
        int ans2 = money[si] + maxMoney(money, n, si + 2, dp);
        dp[si] = max(ans1, ans2);
        return max(ans1, ans2);
    }
}
// Itretive sol
int MaxMoney(int *money, int n)
{
    int *dp = new int[n];
    dp[n - 1] = money[n - 1];
    dp[n - 2] = dp[n - 1];
    for (int i = n - 3; i >= 0; i--)
    {
        dp[i] = max(money[i] + dp[i + 2], dp[i + 1]);
    }
    int ans = dp[0];
    delete[] dp;
    return ans;
}
int main()
{
    int n;
    cout << "Enter number of house: " << endl;
    cin >> n;
    int *money = new int[n];
    cout << "Enter how much money in each house: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> money[i];
    }
    // creat dp
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    int ans1 = MaxMoney(money, n, 0);
    cout << "Recursive sol: " << ans1 << endl;
    int ans2 = maxMoney(money, n, 0, dp);
    cout << "Memoization: " << ans2 << endl;
    int ans3 = MaxMoney(money, n);
    cout << "Itretive sol: " << ans3 << endl;

    delete[] money;
    delete[] dp;
}