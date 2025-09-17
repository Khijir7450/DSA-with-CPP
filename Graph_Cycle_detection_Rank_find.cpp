#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class edge
{

public:
    int source;
    int dest;
    int weight;
};
int findParent(int v, pair<int, int> *parent)
{
    if (parent[v].first == v)
    {
        return v;
    }
    return parent[v].first = findParent(parent[v].first, parent);
}
bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}
void kruskals(edge *input, int v, int e, edge *output, pair<int, int> *parent)
{
    sort(input, input + e, compare);
    int count = 0;
    int i = 0;
    while (count != v - 1)
    {
        edge currEdge = input[i];
        int sourceP = findParent(currEdge.source, parent);
        int destP = findParent(currEdge.dest, parent);
        if (sourceP != destP)
        {
            output[count]=currEdge;
            if (parent[sourceP].second > parent[destP].second)
            {
                parent[destP].first = sourceP;

                // parent[sourceP].second++;
            }
            else if (parent[sourceP].second < parent[destP].second)
            {
                parent[sourceP].first = destP;
            }
            else
            {
                parent[sourceP].first = destP;
                parent[sourceP].second += 1;
            }
            count++;
        }
        i++;
    }
    cout << "MST is:" << endl;
    for (int i = 0; i < v - 1; i++)
    {
        if (output[i].source < output[i].dest)
        {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}
int main()
{
    int v, e;
    cout << "Enter number of vertices and number of edges:" << endl;
    cin >> v >> e;
    cout << "Enter edges like-(source destination weight)" << endl;
    edge *input = new edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    edge *output = new edge[v - 1];
    pair<int, int> *parent = new pair<int, int>[v];
    for (int i = 0; i < v; i++)
    {
        parent[i].first = i;
        parent[i].second = 0;
    }
    kruskals(input,v,e,output,parent);
    delete[] input;
    delete[] output;
    delete[] parent;
}