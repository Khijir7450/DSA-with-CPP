#include <iostream>
#include <cmath>
using namespace std;
float GeometricSum(int n)
{
    if (n == 0)
    {
        return 1;
    }
    float sum = 1 / (pow(2,n)) + GeometricSum(n - 1);
    return sum;
}
int main()
{
    int n;
    cout << "Enter an integer:";
    cin >> n;
    cout << GeometricSum(n);

    return 0;
}