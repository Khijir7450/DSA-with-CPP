#include <bits/stdc++.h>
using namespace std;
// Recursion
int minCost(int **cost, int m, int n, int i, int j)
{
    // Base case
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    // special case or edge case
    if (i == m - 1 && j == n - 1)
    {
        return cost[i][j];
    }
    int ans1 = minCost(cost, m, n, i + 1, j);
    int ans2 = minCost(cost, m, n, i, j + 1);
    int ans3 = minCost(cost, m, n, i + 1, j + 1);
    int myans = cost[i][j] + min(ans1, min(ans2, ans3));
    return myans;
}
// Memoization
int MinCostMemo(int **cost, int m, int n, int i, int j, int **dp)
{
    // Base case
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    // special case or edge case
    if (i == m - 1 && j == n - 1)
    {
        return cost[i][j];
    }
    int ans1;
    if (dp[i + 1][j] == INT_MIN)
    {
        ans1 = MinCostMemo(cost, m, n, i + 1, j, dp);
        dp[i + 1][j] = ans1;
    }
    else
    {
        ans1 = dp[i + 1][j];
    }
    int ans2;
    if (dp[i][j + 1] == INT_MIN)
    {
        ans2 = MinCostMemo(cost, m, n, i, j + 1, dp);
        dp[i][j + 1] = ans2;
    }
    else
    {
        ans2 = dp[i][j + 1];
    }
    int ans3;
    if (dp[i + 1][j + 1] == INT_MIN)
    {
        ans3 = MinCostMemo(cost, m, n, i + 1, j + 1, dp);
        dp[i + 1][j + 1] = ans3;
    }
    else
    {
        ans3 = dp[i + 1][j + 1];
    }
    dp[i][j] = cost[i][j] + min(ans1, min(ans2, ans3));
    return dp[i][j];
}
// Itretive
int MincostItre(int **cost, int m, int n)
{
    int **arr = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i] = new int[n + 1];
    }

    for (int j = 0; j <= n; j++)
    {
        arr[m][j] = INT_MAX;
    }

    for (int j = 0; j <= m; j++)
    {
        arr[j][n] = INT_MAX;
    }
    arr[m][n] = cost[m - 1][n - 1];
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
            {
                arr[i][j] = cost[i][j];
            }
            else
                arr[i][j] = cost[i][j] + min(arr[i + 1][j], min(arr[i][j + 1], arr[i + 1][j + 1]));
        }
    }
    int ans = arr[0][0];
    for (int i = 0; i <= m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return ans;
}
int main()
{
    int m, n;
    cout << "Enter number of row in your matrics:";
    cin >> m;
    cout << endl
         << "Enter number of colomn in your matrics:";
    cin >> n;
    int **cost = new int *[m];
    for (int i = 0; i < m; i++)
    {
        cost[i] = new int[n];
    }
    cout << "Enter cost:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = INT_MIN;
        }
    }
    cout << "Recursion: " << minCost(cost, m, n, 0, 0) << endl;
    cout << "Using memoization:" << MinCostMemo(cost, m, n, 0, 0, dp) << endl;
    cout << "Itretive: " << MincostItre(cost, m, n) << endl;

    for (int i = 0; i < m; i++)
    {
        delete[] cost[i];
    }
    delete[] cost;
    for (int i = 0; i <= m; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
}
/*
  1 5 11
  8 13 12
  2 3 7
  15 16 18
*/