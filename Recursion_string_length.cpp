#include <iostream>
using namespace std;
int lengthOfstr(char str[])
{
    if (str[0]=='\0')
    {
        return 0;
    }
    int length=1+lengthOfstr(str+1);
    return length;
}
int main()
{
  char str[100];
  cout<<"Enter a string:";
  cin>>str;
  cout<<lengthOfstr(str);
 return 0;
}