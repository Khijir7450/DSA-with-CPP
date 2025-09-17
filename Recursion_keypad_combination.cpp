#include <iostream>
using namespace std;
/*int keypadCombi(int n,string output[])
{
    if (n<=0)
    {
        return 1;
    }

    int rem=n%10;
    string small=output[rem];
    return 0;
}*/
int main()
{
    int n;
    cout << "enter a number:";
    cin >> n;
    string option[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int size = 1;
    while (n = 0)
    {
        size = size * (option[n % 10].length());
        n /= 10;
    }
    cout << size;
    return 0;
}