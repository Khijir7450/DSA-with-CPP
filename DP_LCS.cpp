#include <bits/stdc++.h>
using namespace std;
// Recursive sol;
int LCS(string str1, string str2, int i, int j)
{
    if (i == str1.length() || j == str2.length())
    {
        return 0;
    }
    int myans;
    if (str1[i] == str2[j])
    {
        int smallAns = LCS(str1, str2, i + 1, j + 1);
        myans = 1 + smallAns;
    }
    else
    {
        int ans1 = LCS(str1, str2, i + 1, j);
        int ans2 = LCS(str1, str2, i, j + 1);
        myans = max(ans1, ans2);
    }
    return myans;
}
// Memoization
int LCSMemo(string str1, string str2, int i, int j, int **dp)
{
    if (i == str1.length() || j == str2.length())
    {
        return 0;
    }
    int myans;
    if (str1[i] == str2[j])
    {
        int smallAns;
        if (dp[i + 1][j + 1] == -1)
        {
            smallAns = LCS(str1, str2, i + 1, j + 1);
            dp[i + 1][j + 1] = smallAns;
        }
        else
        {
            smallAns = dp[i + 1][j + 1];
        }
        myans = 1 + smallAns;
    }
    else
    {
        int ans1;
        if (dp[i + 1][j] == -1)
        {
            ans1 = LCS(str1, str2, i + 1, j);
            dp[i + 1][j] = ans1;
        }
        else
        {
            ans1 = dp[i + 1][j];
        }
        int ans2;
        if (dp[i][j + 1] == -1)
        {

            ans2 = LCS(str1, str2, i, j + 1);
            dp[i][j + 1] = ans2;
        }
        else
        {
            ans2 = dp[i][j + 1];
        }
        myans = max(ans1, ans2);
    }
    return myans;
}
//Itretive sol
int LCSItre(string str1,string str2,int m,int n){
    int** arr=new int*[m+1];
    for (int i = 0; i <=m; i++)
    {
        arr[i]=new int[n+1];
    }
    for(int i=0;i<=m;i++){
        arr[i][n]=0;
    }
    for(int i=0;i<=n;i++){
        arr[m][i]=0;
    }
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(str1[i]==str2[j]){
                arr[i][j]=1+arr[i+1][j+1];
            }
            else{
                arr[i][j]=max(arr[i+1][j],arr[i][j+1]);
            }
        }
    }
    int ans=arr[0][0];
    for (int i = 0; i <=m; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return ans;
    
    

}
int main()
{
    string str1 = "bedgnc";
    string str2 = "bedgcfnc";
    int m=str1.length();
    int n=str2.length();
    int **dp = new int *[str1.length() + 1];
    for (int i = 0; i <= str1.length(); i++)
    {
        dp[i] = new int[str2.length() + 1];
        for (int j = 0; j <= str2.length(); j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = LCS(str1, str2, 0, 0);
    cout << "Recursion: " << ans<<endl;
    int ans1= LCSMemo(str1,str2,0,0,dp);
    cout<<"using Memoization: "<<ans1<<endl;
    int ans3=LCSItre(str1,str2,m,n);
    cout<<"Itretive sol: "<<ans3<<endl;


    for (int i = 0; i <=m; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    
}