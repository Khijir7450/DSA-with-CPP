#include <iostream>
using namespace std;
int countZeros(int n)
{
    if (n==0)
    {
        return 1;
    }
    
    if (n % 10 == 0)
    {
        return 1 + countZeros(n / 10);
    }
    else
    {
        return countZeros(n / 10);
    }
}
int main()
{
    int n;
    cout << "Enter an Integer number:" << endl;
    cin >> n;
    cout<<"your integer have "<< countZeros(n)<<" zeros";
    return 0;
}