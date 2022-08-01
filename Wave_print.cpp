#include <iostream>
#include <cstring>
using namespace std;
void WavePrint(int arr[][100], int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        if (i == 0 || i % 2 == 0)
        {
            for (int j = 0; j < r; j++)
            {
                cout << arr[j][i];
            }
        }
        else
        {
            for (int j = r - 1; j >= 0; j--)
            {
                cout << arr[j][i];
            }
        }
    }
}
int main()
{
    int arr[100][100];
    int r, c;
    cout << "Enter number of row:";
    cin >> r;
    cout << "Enter number of column:";
    cin >> c;
    cout << "Enter element of matrix:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "your matrix is:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    cout<<"wave print is:"<<endl;
    WavePrint(arr,r,c);
}