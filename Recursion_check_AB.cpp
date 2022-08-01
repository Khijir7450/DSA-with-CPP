#include <iostream>
using namespace std;
bool checkAB(char str[], int size)
{
    if (size == 0)
    {
        return true;
    }
    if (str[0] == 'a')
    {
        if (str[1] == '0' || (str[1] == 'b' && str[2] == 'b'))
        {
            if (str[1] == '0')
            {
                return true;
            }
            else if(str[3] == '0' || str[3] == 'a')
                {
                    if (str[3] == '0')
                    {
                        return true;
                    }
                    else
                    {
                        return checkAB(str + 3, size - 3);
                    }
                }
        }
        else
            return false;
    }
    else
        return false;
}
int main()
{
    int n;
    cout << "Enter size of string:";
    cin >> n;
    char str[100];
    cout << "Enter string element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    cout << endl
         << "your string is:";
    for (int i = 0; i < n; i++)
    {
        cout << str[i];
    }

    if (checkAB(str, n))
    {
        cout <<endl<< "true";
    }
    else
        cout <<endl<< "false";

    return 0;
}