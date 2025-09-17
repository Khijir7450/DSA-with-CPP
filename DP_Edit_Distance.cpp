#include <bits/stdtr1c++.h>
using namespace std;
// Recursive sol
int Edit_Distance(string s1, string s2)
{
    if (s1.length() == 0 && s2.length() == 0)
    {
        return 0;
    }
    if (s1.length() == 0)
    {
        return s2.length();
    }
    if (s2.length() == 0)
    {
        return s1.length();
    }
    int ans;
    if (s1[0] == s2[0])
    {
        return Edit_Distance(s1.substr(1), s2.substr(1));
    }
    else
    {
        int ans1 = Edit_Distance(s1.substr(1), s2.substr(1));
        int ans2 = Edit_Distance(s1.substr(1), s2);
        int ans3 = Edit_Distance(s1, s2.substr(1));
        ans = 1 + min(ans1, min(ans2, ans3));
    }
    return ans;
}
// Memoization
int Edit_Distance(string s1, string s2, int **dp)
{
    int m = s1.length();
    int n = s2.length();
    if (m == 0 || n == 0)
    {
        return max(m, n);
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    else
    {

        int ans;
        if (s1[0] == s2[0])
        {
            ans = Edit_Distance(s1.substr(1), s2.substr(1), dp);
        }
        else
        {
            int ans1 = Edit_Distance(s1.substr(1), s2.substr(1), dp);

            int ans2 = Edit_Distance(s1.substr(1), s2, dp);

            int ans3 = Edit_Distance(s1, s2.substr(1), dp);

            ans = 1 + min(ans1, min(ans2, ans3));
            dp[m - 1][n - 1] = ans;
        }
        return ans;
    }
}
// Itretive sol
int EditDistance_Itre(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        output[i][0] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        output[0][i] = i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i]==s2[n-j]){
                output[i][j]=output[i-1][j-1];
            }
            else{
                output[i][j]=min(output[i-1][j-1], min(output[i][j-1], output[i-1][j]));
            }
        }
    }
    int ans=output[m][n];
    for (int i = 0; i <=m; i++)
    {
        delete [] output[i];
    }
    delete [] output;
    return ans;
    
}
int main()
{
    string s1 = "abcd";
    string s2 = "ab";
    int **dp = new int *[s1.length() + 1];
    for (int i = 0; i <= s1.length(); i++)
    {
        dp[i] = new int[s2.length() + 1];
        for (int j = 0; j <= s2.length(); j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = Edit_Distance(s1, s2);
    cout << "Recursion: " << ans << endl;
    int ans1 = Edit_Distance(s1, s2, dp);
    cout << "Memoization: " << ans1 << endl;
    int ans3=EditDistance_Itre(s1,s2);
    cout<<"Itretion:"<<ans3<<endl;

    // delete
    for (int i = 0; i <= s1.length(); i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
}