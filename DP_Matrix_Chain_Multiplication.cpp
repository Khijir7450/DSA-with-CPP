#include <bits/stdc++.h>
using namespace std;
int minimumNoOperation(int *arr, int s, int e)
{
    if (s == e || e - 1 == s)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = s + 1; k < e; k++)
    {
        int ans1 =minimumNoOperation(arr, s, k) + minimumNoOperation(arr, k, e)+(arr[s] * arr[k] * arr[e]);
        ans = min(ans, ans1);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the Number of Matrix: " << endl;
    cin >> n;
    int *arr = new int[n + 1];
    cout << "Enter Dimention of Matrix: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << minimumNoOperation(arr, 0, n);
    delete[] arr;
}