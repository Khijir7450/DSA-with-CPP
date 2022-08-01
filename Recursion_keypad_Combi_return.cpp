#include <iostream>
#include <cmath>
#include <cmath>
using namespace std;
int KeyPadCombo(int n, string option[], string *output)
{
    if (n == 0)
    {
        output[0] = "";
        return 1;
    }
    int SmallAns = KeyPadCombo(n / 10, option, output);
    for (int i = 0; i < SmallAns; i++)
    {
        int j = 0;
        while (j < option[n % 10].size())
        {
            output[i + SmallAns] = output[i] + option[n % 10][j];
            j++;
        }
    }
    return option[n % 10].size() * SmallAns;
}
int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    int m=n;
    string option[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int size_of_output = 1;
    while (n > 0)
    {
        size_of_output = size_of_output * (option[n % 10].length());
        n /= 10;
    }
    string *output = new string[size_of_output];
    int size = KeyPadCombo(m,option, output);
    for (int i = 0; i <size; i++)
    {
        cout << output[i] << endl;
    }
}