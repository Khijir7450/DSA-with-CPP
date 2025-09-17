#include <bits/stdc++.h>
using namespace std;
// Recursive sol;
int Num_Code(int *arr, int size)
{
    if (size == 1 || size == 0)
    {
        return 1;
    }
    int output = Num_Code(arr, size - 1);
    if ((((arr[size - 2]) * 10) + (arr[size - 1])) <= 26)
    {
        // cout << "call;" << endl;
        output += Num_Code(arr, size - 2);
    }
    return output;
}
// dp
int Num_CodeDp(int *arr, int *dp, int size)
{
    cout << "hey madafak" << endl;
    if (size == 1 || size == 0)
    {
        return 1;
    }
    if (dp[size] > 0)
    {
        return dp[size];
    }
    int output = Num_CodeDp(arr, dp, size - 1);

    if ((arr[size - 2] * 10 + arr[size - 1]) <= 26)
    {
        output += Num_CodeDp(arr, dp, size - 2);
    }
    dp[size] = output;
    return output;
}
// memoization
int Num_CodeMemo(int *arr, int size)
{
    int *output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;
    for (int i = 2; i <= size; i++)
    {
        output[i] = output[i - 1];
        if ((arr[i - 2] * 10 + arr[i - 1]) <= 26)
        {
            output[i] += output[i - 2];
        }
    }
    int ans = output[size];
    delete[] output;
    return ans;
}
int main()
{
    int n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }
    // int ans1 = Num_Code(arr, n);
    int ans2 = Num_CodeDp(arr, dp, n);
    // int ans3=Num_CodeMemo(arr,n);
    // cout << "Recursion: " << ans1 << endl;
    cout << "using dp: " << ans2 << endl;
    // cout<<"memo: "<<ans3<<endl;
    delete[] arr;
    delete[] dp;
}
