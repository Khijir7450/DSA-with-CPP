#include <bits/stdc++.h>
using namespace std;
void SubsetHelper(int *arr,vector<vector<int>> &ans, int n,  int index)
{
    // if(n==index){
    //     return;
    // }
    if ((n - index) == 1)
    {
        ans.push_back({});
        ans.push_back({arr[index]});
        return;
    }
    SubsetHelper(arr, ans, n, index + 1);
    for (int i = 0; i < ans.size(); i++)
    {
        vector<int> temp;
        temp.push_back(arr[index]);
        for (int j = 0; j < ans[i].size(); j++)
        {
            temp.push_back(ans[i][j]);
        }
        ans.push_back(temp);
    }
    return;
}
int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans;
    int index = 0;
    SubsetHelper(arr, ans, n, index);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}