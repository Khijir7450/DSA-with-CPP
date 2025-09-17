#include <iostream>
using namespace std;
void increment(int &i)
{
    i++;
    cout << i;
}
int main()
{
    int i = 10;
    int &j = i;
    cout << j << " " << i << endl;
    j++;
    cout << j << " " << i << endl;
    i++;
    cout << j << " " << i << endl;
    increment(i);
    cout << endl;
    increment(j);
    cout << endl;

    return 0;
}