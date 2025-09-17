#include<iostream>
using namespace std;
void print(int brr[]){
    cout<<"size from fn "<<sizeof(brr)/sizeof(int)<<endl;
    cout<<"array 0 "<<brr[3]<<endl;
}
int main(){
    int arr[15]={1,2,3,4,5};
    print(arr);
    cout<<"size from main "<<sizeof(arr)/sizeof(int);

}