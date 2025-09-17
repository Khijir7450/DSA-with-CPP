#include <bits/stdc++.h>
using namespace std;
bool has_path(int **edges, int n, int s, int e, bool *visited)
{
    if (edges[s][e] == 1)
    {
        return true;
    }
    queue<int> pendingVertices;
    pendingVertices.push(s);
    visited[s] = true;
    while (!pendingVertices.empty())
    {
        int cv = pendingVertices.front();
        pendingVertices.pop();
        if (cv == e)
        {
            return true;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && edges[s][i] == 1)
                {
                    pendingVertices.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int v, e;
    cout << "Enter number of Vertices:";
    cin >> v;
    cout << "Enter number of Edges:";
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
    cout << "Enter Edges(like 1 2):" << endl;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    int source, destination;
    cout << "Enter two vertices for knowing has a path or not:" << endl;
    cin >> source >> destination;
    if (has_path(edges, v, source, destination, visited))
    {
        cout << "yes there has path between " << source << " and " << destination;
    }
    else
    {
        cout << "there no path between " << source << " and " << destination;
    }
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete [] visited;
}