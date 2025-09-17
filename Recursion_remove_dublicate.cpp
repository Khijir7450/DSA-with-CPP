#include <iostream>
#include <cstring>
using namespace std;
void RemoveDublicate(char ar[], int size)
{
    if (size == 1)
    {
        return;
    }

    else if (ar[0] == ar[1])
    {
        for (int j = 0; j <= size; j++)
        {
            ar[j] = ar[j + 1];
        }
        RemoveDublicate(ar, size - 1);
    }
    RemoveDublicate(ar + 1, size - 1);
}
int main()
{
    char str[] = "xxxyyyzwwzzz";
    int len = strlen(str);
    RemoveDublicate(str, len);
    cout << str;

    return 0;
}