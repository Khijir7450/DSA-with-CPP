#include <bits/stdc++.h>
using namespace std;
// Recursive sol
int minimunStep(int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    int n1 = 1 + minimunStep(n - 1);
    int n2 = INT_MAX;
    if (n % 2 == 0)
    {
        n2 = 1 + minimunStep(n / 2);
    }
    int n3 = INT_MAX;
    if (n % 3 == 0)
    {
        n3 = 1 + minimunStep(n / 3);
    }
    return min(n1, min(n2, n3));
}
//Memoization dp
int MinimunStep(int n, int *dp)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int n1 = 1 + MinimunStep(n - 1,dp);
    int n2 = INT_MAX;
    if (n % 2 == 0)
    {
        n2 = 1 + MinimunStep(n / 2,dp);
    }
    int n3 = INT_MAX;
    if (n % 3 == 0)
    {
        n3 = 1 + MinimunStep(n / 3,dp);
    }
    dp[n]=min(n1, min(n2, n3));
    return dp[n];
}
//Itretive dp
int MinStepToOne(int n){
    int* arr=new int[n+1];
    arr[0]=0;
    arr[1]=0;
    for(int i=2;i<=n;i++){
        int n1=arr[i-1];
        int n2=INT_MAX;
        if(i%2==0){
            n2=arr[i/2];
        }
        int n3=INT_MAX;
        if(i%3==0){
            n3=arr[i/3];
        }
        arr[i]=1+min(n1,min(n2,n3));
    }
    int ans=arr[n];
    delete [] arr;
    return ans;
}
int main()
{
    int n;
    cout << "Enter a number:" << endl;
    cin >> n;
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = 0;
    cout << "Using Recursion: " << minimunStep(n) << endl;
    cout << "Using memoization dp: " << MinimunStep(n, dp) << endl;
    cout << "Using Itretive dp: " << MinStepToOne(n) << endl;

    delete [] dp;
}