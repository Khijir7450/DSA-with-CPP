#include <iostream>
using namespace std;
void TowerOfHanoi(int n,char s,char a,char d)
{
    if (n==1)
    {
        cout<<"move disk "<<n<<" form "<<s<<" to "<<d<<endl;
        return;
    }
    TowerOfHanoi(n-1,s,d,a);
    cout<<"move disk "<<n<<" form "<<s<<" to "<<d<<endl;
    TowerOfHanoi(n-1,a,s,d);
    
    
}
int main()
{
  int n;
  cout<<"Enter number of disk:";
  cin>>n;
  char source='S';
  char destenation='D';
  char assume='A';
  TowerOfHanoi(n,source,assume,destenation);
 return 0;
}