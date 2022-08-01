#include <bits/stdc++.h>
using namespace std;
int Knapsack(int w[], int v[], int wt, int n, int si)
{
    if (wt == 0)
    {
        return 0;
    }
    if (si == n)
    {
        return 0;
    }
    if (w[si] <= wt)
    {
        int ans1 = v[si] + Knapsack(w, v, wt - w[si], n, si + 1);
        int ans2 = Knapsack(w, v, wt, n, si + 1);
        return max(ans1, ans2);
    }
    else
    {
        return Knapsack(w, v, wt, n, si + 1);
    }
}
// memoization
int Knapsack(int w[], int v[], int n, int mw, int si, int **dp)
{
    if (mw == 0)
    {
        dp[mw][si] = 0;
        return 0;
    }
    if (si == n)
    {
        dp[mw][n] = 0;
        return 0;
    }
    if (dp[mw][si] == -1)
    {
        if (w[si] <= mw)
        {
            int ans1 = v[si] + Knapsack(w, v, n, mw - w[si], si + 1, dp);
            int ans2 = Knapsack(w, v, n, mw, si + 1, dp);
            dp[mw][si] = max(ans1, ans2);
            return max(ans1, ans2);
        }
        else
        {
            return Knapsack(w, v, n, mw, si + 1, dp);
        }
    }
    else
    {
        return dp[mw][si];
    }
}
// Itretive
int Knapsack(int w[], int v[], int n, int mw)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[mw + 1];
    }
    for (int i = 0; i <= mw; i++)
    {
        dp[n][i] = 0;
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[n][0] = 0;
    // }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= mw; j++)
        {
            int ans;
            if (w[i] <= j)
            {
                int ans1 = v[i] + dp[i + 1][j - w[i]];
                int ans2 = dp[i + 1][j];
                ans = max(ans1, ans2);
            }
            else
            {
                ans = dp[i + 1][j];
            }
            dp[i][j] = ans;
        }
    }
    int ans=dp[0][mw];
    for (int i = 0; i <=n; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    
    return ans;
}
int main()
{
    int weight[7] = {1, 2, 4, 5, 6, 7, 9};
    int value[7] = {5, 4, 8, 6, 3, 7, 10};
    int n = 7;
    int mw = 15;
    int **dp = new int *[mw + 1];
    for (int i = 0; i <= mw; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans1 = Knapsack(weight, value, mw, n, 0);
    int ans2 = Knapsack(weight, value, n, mw, 0, dp);
    int ans3=Knapsack(weight,value,n,mw);
    cout << "Recursive sol: " << ans1 << endl;
    cout << "memo: " << ans2 << endl;
    cout<<"Itretive: "<<ans3<<endl;

    for (int i = 0; i <= mw; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
}