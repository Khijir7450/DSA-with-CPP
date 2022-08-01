#include<bits/stdc++.h>
using namespace std;
int First_Index(int arr[],int x,int start,int n){
    if(start==n){
        return -1;
    }
    if(arr[start]==x){
        return start;
    }
    return First_Index(arr,x,start+1,n-1);
}
int Find_Last_Index(int arr[],int x,int start,int n){
     if(start==0){
        return -1;
    }
     if(arr[start]==x){
        return start;
    }
    return First_Index(arr,x,start-1,n-1);
}
int main(){
    int arr[]={1,2,3,5,2,6,2};
    int size=7;
    cout<<First_Index(arr,2,0,7)<<endl;
    cout<<Find_Last_Index(arr,2,size-1,7);
}