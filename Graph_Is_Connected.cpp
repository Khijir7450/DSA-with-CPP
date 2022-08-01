#include <bits/stdc++.h>
using namespace std;
void Isconnected(int **edges, int v, int sv, bool *visited)
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
            Isconnected(edges, v, i, visited);
        }
    }
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
    Isconnected(edges, v, 0, visited);
    int i = 0;
    for (; i < v; i++)
    {
        if(!visited[i]){
            cout<<"your Graph is not connected"<<endl;
            break;
        }

    }
    if(i>=v){
        cout<<"Your Graph is connected"<<endl;
    }


    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}