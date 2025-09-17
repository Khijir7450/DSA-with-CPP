#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    int i=0;//if u want sum of odd number then i=1;
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    while (i<=n)
    {
        sum=sum+i;
        i=i+2;//if you want sum of nutural number then i=i+1|| i++;
    }
    cout<<sum;

}
