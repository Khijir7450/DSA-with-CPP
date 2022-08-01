#include <bits/stdc++.h>
using namespace std;
// no duplicate digits in number
int num(int *input, int n, int *fact, int *freq)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    int ans = 0;
    for (int i = input[0] + 1; i < 10; i++)
    {
        if (freq[i] > 0)
        {
            ans += fact[n - 1];
        }
    }
    freq[input[0]]--;
    ans += num(input + 1, n - 1, fact, freq);
    return ans;
}
// in case of duplicate
int denomrator(int* freq,int* fact){
    int ans=1;
    for(int i=0;i<=9;i++){
        ans*=fact[freq[i]];
    }
    return ans;
}
int numForDuplicate(int *input, int n, int *freq, int *fact)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    int ans = 0;

    for (int i = input[0] + 1; i < 10; i++)
    {
        if (freq[i] > 0)
        {
            ans+=(fact[n-1]*freq[i])/denomrator(freq,fact);
        }
    }
    freq[input[0]]--;
    ans+=numForDuplicate(input+1,n-1,freq,fact);
    return ans;
}
int main()
{
    int n;
    cout << "Enter no of digits:";
    cin >> n;
    int *input = new int[n];
    int *fact = new int[n + 1];
    fact[0] = 1;
    int freq[10] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        freq[input[i]]++;
        fact[i + 1] = (i + 1) * fact[i];
    }
    cout<< "No of Numbers Duplicate:"<<numForDuplicate(input,n,freq,fact)<<endl;
    cout << "No of Numbers:" << num(input, n, fact, freq) << endl;
}