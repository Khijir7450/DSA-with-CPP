#include<bits/stdc++.h>
using namespace std;
int minimunCount(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    int ans=n;
    for (int i = 1; i*i<=n; i++)
    {
        ans=min(ans, 1+minimunCount(n-i*i));
    }
    return ans;
   

}
int main(){
    int n;
    cout<<"Enter a Number:";
    cin>>n;
    cout<<minimunCount(n);
}