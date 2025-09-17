#include <iostream>
#include<string>
#include <cmath>
using namespace std;
int SubS(string input, string *output)
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string smallS = input.substr(1);
    int SmallAns = SubS(smallS, output);
    for (int i = 0; i < SmallAns; i++)
    {
        output[i+SmallAns]=input[0]+output[i];
    }
    return 2*SmallAns;
}
int main()
{
    string input;
    cin >> input;
    int n=pow(2,input.size());
    string *output = new string[n];
    int count = SubS(input, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}