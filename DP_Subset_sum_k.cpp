#include <bits/stdc++.h>
using namespace std;
//recursive sol
bool SubsetSumKorNot(int *arr,int n,int sum,int si)
{
    if (si >= n && sum!=0)
    {
        return false;
    }
    if(sum==0){
        return true;
    }
    return (SubsetSumKorNot(arr,n,sum,si+1) || SubsetSumKorNot(arr,n,sum-arr[si],si+1));
}
//Itretive sol
bool isSubsetSumK(int* arr,int n,int sum){
    bool** dp=new bool*[n+1];
    for (int i = 0; i <=n; i++)
    {
        dp[i]=new bool[sum+1];
    }
    //first colomn
    for (int i = 0; i <=n; i++)
    {
        dp[i][0]=true;
    }
    //first row
    for (int i = 1; i <=sum; i++)
    {
        dp[0][i]=false;
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=sum; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1]){
                dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
    }
    bool ans=dp[n][sum];
    for (int i = 0; i <=n; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
    
    
    
    
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cout << "Enter sum: ";
    cin >> sum;
    if(SubsetSumKorNot(arr,n,sum,0)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    if(isSubsetSumK(arr,n,sum)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

    //delete
    delete [] arr;
}