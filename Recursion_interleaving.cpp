#include <bits/stdc++.h>
using namespace std;
void interLeaving(string s, string t, string p, int n, int m, int i)
{
    if (n == 0 && m == 0)
    {
        cout << p << endl;
        // p->erase();
        return;
    }
    if (n >= 1)
    {
        p.push_back(s[0]);
        interLeaving(s.substr(1), t, p, n - 1, m, i + 1);
    }
    if (m >= 1)
    {
        p.push_back(t[0]);
        interLeaving(s, t.substr(1), p, n, m - 1, i + 1);
    }
}
int main()
{
    string s = "abc";
    string t = "def";
    int n = s.length();
    int m = t.length();
    string ans = "";
    // char *a = new char[m + n+1];
    // a[m+n]='\0';
    interLeaving(s, t, ans, n, m, 0);
}