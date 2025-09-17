#include <iostream>
using namespace std;
void print(int n){
    if(n < 0){
        return;
    }
    if(n == 0){
        cout << n << " ";
        return;
    }
    print(n --);
    cout << n << " ";
}

int main() {
    int num = 3;
    print(num);
}
/*int fibonacci(int n)
{
    if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    int fib=fibonacci(n-1)+fibonacci(n-2);
    return fib;
    
}
int main()
{
  int n;
  cout<<"Enter index:";
  cin>>n;
  cout<<endl<<fibonacci(n); 
 return 0;
}*/