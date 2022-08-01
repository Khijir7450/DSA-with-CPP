#include<bits/stdc++.h>
using namespace std;
bool getBit(int n,int i){
    return (n&(1<<i));
}
int setBit(int n,int i){
    return (n|1<<i);
}
int clearBit(int n,int i)
{
    int mask=~(1<<i);
    return (n & mask);
}
int main(){
    int n;
    cout<<"Enter number:"<<endl;
    cin>>n;
    int i;
    cout<<"Enter bit: ";
    cin>>i;
    cout<<"ith bit is: "<<getBit(n,i)<<endl;
    cout <<"After set the ith bit, the number become: "<<setBit(n,i)<<endl;
    cout<<"After clear the ith bit: "<<clearBit(n,i);
}