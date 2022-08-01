#include <bits/stdc++.h>
using namespace std;
void dfs(int **edges, int v, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            dfs(edges, v, i, visited);
        }
    }
}
int bfs(int **edges, int v)
{
    int count = 0;
}
int DFS(int **edges, int v)
{
    int count = 0;
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfs(edges, v, i, visited);
            count++;
        }
    }
    delete [] visited;
    return count;
}
int main()
{
    int v, e;
    cout << "Enter number of Islands:";
    cin >> v;
    cout << "Enter number of connection:";
    cin >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    cout << "Enter connection(like- Island1 Island2):" << endl;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout << "DFS:" << endl;
    cout<<DFS(edges, v);
    // cout << "BFS:" << endl;
    // BFS(edges, v);

    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}