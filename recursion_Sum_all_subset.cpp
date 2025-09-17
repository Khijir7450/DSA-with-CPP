#include<bits/stdc++.h>
using namespace std;
vector<int> SumOfAllSubset(int* arr,int n,int* ans,int sum){
    if(n==0){
        vector<int> ans;
        return ans;
    }
    if(n==1){
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(arr[0]);
        return ans;
    }
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter array element:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int* ans=new int[n];

}