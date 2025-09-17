#include<iostream>
using namespace std;
int Multiplication(int n,int m){
    if(m==0||n==0){
        return 0;
    }
    if(m==1){
        return n;
    }
    int ans = Multiplication(n,m-1);
    return ans+n;

}
int main(){
    int n,m;
    cout<<"Enter two number for Multiplication:"<<endl;
    cin>>n>>m;
    cout<<Multiplication(n,m)<<endl;
}

