#include <bits/stdc++.h>
using namespace std;
vector<int> get_Path(int** edges,int v, int s,int d,bool* visited){
    vector<int>ans;
    if(s==d){
        ans.push_back(s);
        return ans;
    }
    visited[s]=true;
    for(int i=0; i<v;i++){
        if(i==s){
            continue;
        }
        if(edges[s][i]==1 && !visited[i]){
            if(i==d){
                
                ans.push_back(i);
                ans.push_back(s);
                return ans;
            }
            else{
                ans=get_Path(edges,v,i,d,visited);
                if(ans.size()>0){
                    visited[i]=true;
                    ans.push_back(s);
                    return ans;
                }
            }
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
    int source, destination;
    cout << "Enter two vertices for knowing has a path or not:" << endl;
    cin >> source >> destination;
    vector<int> ans=get_Path(edges,v,source,destination,visited);
    if(ans.size()>0){
        cout<<"path is:"<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        cout<<"Koi path nehi hain";
    }




    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}