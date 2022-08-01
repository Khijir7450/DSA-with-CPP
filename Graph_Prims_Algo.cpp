#include <bits/stdc++.h>
using namespace std;
int findMinVertex(int *weight, bool *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(int **edge, int n)
{
    int *parent = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    for (int i = 0; i < n-1; i++)
    {
        // find min vertex
        int minVertex = findMinVertex(weight, visited, n);
        visited[minVertex] = true;
        // Explore un visited neighbours
        for (int j = 0; j < n; j++)
        {
            if (edge[minVertex][j] != 0 && !visited[j])
            {
                if (edge[minVertex][j] < weight[j])
                {
                    weight[j] = edge[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
    // delete[] parent;
    // delete[] weight;
    // delete[] visited;
}

int main()
{

    int v, e;
    cout << "Enter number of Vertices and edges:"<<endl;
    cin >> v >> e;

    int **edge = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edge[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edge[i][j] = 0;
        }
    }
    cout << "Enter Edges(like- vertices1 vertices2 weight):" << endl;
    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edge[f][s] = w;
        edge[s][f] = w;
    }
    cout << endl;
    prims(edge, v);

    for (int i = 0; i < v; i++)
    {
        delete[] edge[i];
    }
    delete[] edge;
}
/*
8 13
0 3 1
0 1 4
0 2 9
3 2 8
1 2 2 
1 4 6
1 5 11
2 5 3
4 5 12
4 6 13
4 7 5
5 7 10
6 7 7
*/