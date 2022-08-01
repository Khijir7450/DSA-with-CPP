#include<iostream>
using namespace std;
// last index
int LastIndexOfK(int*arr,int k,int start){
    if(start<0){
        return -1;
    }
    if(arr[start]==k){
        return start;
    }
    return LastIndexOfK(arr,k,start-1);
}
//First Index
int FirstIndexOfK(int*arr,int k,int start){
    if(start<0){
        return -1;
    }
    if(arr[start]==k){
        return start;
    }
    return FirstIndexOfK(arr,k,start+1);
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter Array element:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the K"<<endl;
    cin>>k;
    cout<<"Last index of "<<k<<" is: "<<LastIndexOfK(arr,k,n-1)<<endl;
    cout<<"First index of "<<k<<" is: "<<FirstIndexOfK(arr,k,0)<<endl;
}