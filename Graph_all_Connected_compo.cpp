#include <bits/stdc++.h>
using namespace std;
void ACC(int **edges, int v, int sv, bool *visited, vector<vector<int>> &ans)
{
    vector<int> a;
    a.push_back(sv);
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
            else
            {
                a.push_back(i);
                visited[i] = true;
            }
        }
    }
    ans.push_back(a);
}
vector<vector<int>> AllConnectedCompo(int **edges, int v, bool *visited)
{
    vector<vector<int>> ans;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            ACC(edges, v, i, visited, ans);
        }
    }
    return ans;
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
    vector<vector<int>> ans=AllConnectedCompo(edges, v, visited);
    cout << "All connected componant are:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}