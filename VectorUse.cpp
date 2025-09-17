#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    v[1]=100;
    // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    v[3]=40;
    v[4]=50; 
    v.push_back(60); 
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[4]<<" "<<v[5]<<endl;
    // cout<<v[7]<<endl;
    
}