#include <iostream>
using namespace std;
void RemoveX(char s[])
{
    if (s[0]=='\0')
    {
        return;
    }
    if (s[0]!='x')
    {
        RemoveX(s+1);
    }
    if (s[0]=='x')
    {
        int i=1;
        for (; s[i]!='\0'; i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        RemoveX(s);
        
    }
    
    
    
}
int main()
{
  char str[100];
  cout<<"Enter a string:";
  cin>>str;
  RemoveX(str);
  cout<<str;
 return 0;
}