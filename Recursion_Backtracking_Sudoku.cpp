#include <bits/stdc++.h>
using namespace std;
bool IsValid(int **bord, int x, int y, int k)
{
    for (int i = 0; i < 9; i++)
    { // horizontal
        if (bord[x][i] == k)
        {
            return false;
        }
        // vertical
        if (bord[i][y] == k)
        {
            return false;
        }
    }
    // inside block
    int strx = x / 3;
    int stry = y / 3;
    strx *= 3;
    stry *= 3;
    for (int i = strx; i < strx + 3; i++)
    {
        for (int j = stry; j < stry + 3; j++)
        {
            if (bord[i][j] == k)
            {
                return false;
            }
        }
    }
    return true;
}
bool IsValidSudoku(int **bord, int **visited, int x, int y)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (bord[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (IsValid(bord, i, j, k))
                    {
                        bord[i][j] = k;
                        visited[i][j] = 1;
                        if (IsValidSudoku(bord, visited, i, j))
                        {
                            return true;
                        }
                        bord[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int **bord = new int *[9];
    cout << "Enter Unsolved Sudoku:" << endl;
    for (int i = 0; i < 9; i++)
    {
        bord[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            cin >> bord[i][j];
        }
    }
    int **visited = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        visited[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            visited[i][j] = 0;
        }
    }
    cout << IsValidSudoku(bord, visited, 0, 0) << endl;
    // delete 2D array
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << bord[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 9; i++)
    {
        delete[] bord[i];
        delete[] visited[i];
    }
    delete[] bord;
    delete[] visited;
    /*
    9 0 0 0 2 0 7 5 0
    6 0 0 0 5 0 0 4 0
    0 2 0 4 0 0 0 1 0
    2 0 8 0 0 0 0 0 0
    0 7 0 5 0 9 0 6 0
    0 0 0 0 0 0 4 0 1
    0 1 0 0 0 5 0 8 0
    0 9 0 0 7 0 0 0 4
    0 8 2 0 4 0 0 0 6
    */
}