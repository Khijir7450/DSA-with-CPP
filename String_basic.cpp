#include <iostream>
using namespace std;
int main()
{
    string s;
    s="abcd";
   // cin.getline(s);
    getline(cin,s);
   // cin>>s;
    cout<<s<<endl;
    cout<<s.size()<<endl;
    cout<<s.substr(6)<<endl;
      cout<<s.substr(0,6)<<endl;
      cout<<s.find("k")<<endl;
    string* sp=new string;
    *sp="xxxxx";
    cout<<sp<<endl<<*sp<<endl;
    *sp="yyyyy";
     cout<<sp<<endl<<*sp<<endl;
 return 0;
}