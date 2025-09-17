#include <iostream>
#include <string>
using namespace std;
void Printkpad(int n,string output,string options[])
{
    if (n<=1)
    {
        cout<<output<<endl;
    }
    int n1=n%10;
    string s1=options[n1];
    for (int i = 0; i < s1.length(); i++)
    {
        Printkpad(n/10,s1[i]+output,options);
    }
    
    
}
void printKeypad(int n)
{
    string output = "";
    string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    Printkpad(n,output,options);

}

int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    printKeypad(n);
    return 0;
}