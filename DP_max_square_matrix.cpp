#include <bits/stdc++.h>
using namespace std;

int maximalSquare(int** matrix,int m,int n)
{
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (matrix[0][i] == 1)
        {
            dp[0][i] = 1;
            ans = max(dp[0][i], ans);
        }
        else
        {
            dp[0][i] = 0;
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (matrix[i][0] == 1)
        {
            dp[i][0] = 1;
            ans = max(dp[i][0], ans);
        }
        else
        {

            dp[i][0] = 0;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                ans = max(dp[i][j], ans);
            }
        }
    }
    for(int i=0;i<m;i++){
        delete [] dp[i];
    }
    delete dp;
    return ans*ans;
}
int main()
{
    int m;
    cout << "Enter row: " << endl;
    cin >> m;
    int n;
    cout << "Enter col: " << endl;
    cin >> n;
    int** matrix=new int*[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i]=new int[n];
    }
    
    cout << "Enter matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int ans=maximalSquare(matrix,m,n);
    cout<<"Maximum matrix:"<<ans;

}