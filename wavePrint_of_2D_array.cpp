#include <bits/stdc++.h>
using namespace std;
void WavePrint(int **arr, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        // top to down print
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            }
        }
    }
}
int main()
{
    int m, n;
    cout << "Enter size of row:";
    cin >> m;
    cout << "Enter size of colomn:";
    cin >> n;
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    cout << "Enter array element:";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    WavePrint(arr,m,n);


    for (int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}