#include<iostream>
using namespace std;
int FindDuplicate(int *arr,int n){
    int i=0,j;
    while(i<n){
        j=i+1;
        while(j<n){
            if(arr[i]==arr[j]){
                return arr[i];
            }
            else{
                j++;
            }
        }
        i++;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter array element(which belong in 0 to"<< n-2<<" and one elment is duplicate)"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<FindDuplicate(arr,n);



    delete []arr;
}