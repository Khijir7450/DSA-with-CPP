#include <bits/stdc++.h>
using namespace std;
class Triplate
{
public:
    int x;
    int y;
    int gcd;
};
Triplate ExtendedEuclid(int a, int b)
{
    if (b == 0)
    {
        Triplate ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    // Extended Euclid algo
    Triplate smallAns = ExtendedEuclid(b, a % b);
    Triplate ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    Triplate ans=ExtendedEuclid(a, b);
    cout<<"GCD:"<<ans.gcd<<endl;
    cout<<"value of x: "<<ans.x<<endl;
    cout<<"value of y: "<<ans.y<<endl;
    return 0;
}