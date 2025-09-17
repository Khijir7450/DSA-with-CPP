#include <iostream>
#include <cmath>
using namespace std;
int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = " ";
        return 1;
    }
    string small = input.substr(1);
    int smalloutput = subs(small, output);
    for (int i = 0; i < smalloutput; i++)
    {
        output[i + smalloutput] = input[0] + output[i];
    }
    return (2 * smalloutput);
}
int main()
{
    string input;
    getline(cin, input);
    int Size = input.size();
    int S_output = pow(2,Size);
    string *output = new string[S_output];
    // string* output=new string[1000];
    int count = subs(input, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}