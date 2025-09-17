#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int source;
    int dest;
    int weight;
};
int findParent(int v, int* parent){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v],parent);
}
bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}
void Kruskals(edge *input, int v, int e)
{ // sort the input array based on weight;
    sort(input, input + e, compare);
    edge *output = new edge[v - 1];
    int* parent=new int[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    int count = 0;
    int i = 0;
    while (count != v - 1)
    {
        edge currEdge = input[i];
        //check if we can add the currEdge in MST or not;
        // we have to find the parent of source and destination;
        int sourceP=findParent(currEdge.source,parent);
        int destP=findParent(currEdge.dest,parent);
        if(sourceP!=destP){
            output[count]=currEdge;
            count++;
            parent[sourceP]=destP;
        }
        i++;

    }
    cout<<"MST is:"<<endl;
    for (int i = 0; i < v-1; i++)
    {
        if(output[i].source<output[i].dest){
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
             cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }

    
}
int main()
{
    int v, e;
    cin>>v>>e;
    edge *input = new edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    Kruskals(input, v, e);
}
