#include<bits/stdc++.h>
using namespace std;
void PrintAllPath(int** maze,int n, int** ans, int x,int y){
    if(x==n-1 && y==n-1){
        ans[x][y]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    if(x<0 || y<0 ||x>=n ||y>=n ||maze[x][y]==0|| ans[x][y]==1){
        return;
    }
    ans[x][y]=1;
    PrintAllPath(maze,n,ans,x-1,y);
    PrintAllPath(maze,n,ans,x+1,y);
    PrintAllPath(maze,n,ans,x,y+1);
    PrintAllPath(maze,n,ans,x,y-1);
    ans[x][y]=0;

}
bool HaspathHelper(int** maze,int n,int** ans,int x,int y){
    if(x==n-1 && y==n-1){
        return true;
    }
    if(x<0 || y<0 ||x>=n ||y>=n ||maze[x][y]==0|| ans[x][y]==1){
        return false;
    }
    ans[x][y]=1;
    if(HaspathHelper(maze,n,ans,x-1,y)){
        return true;
    }
    if(HaspathHelper(maze,n,ans,x+1,y)){
        return true;
    }
    if(HaspathHelper(maze,n,ans,x,y-1)){
        return true;
    }
    if(HaspathHelper(maze,n,ans,x,y+1)){
        return true;
    }
    ans[x][y]=0;
    return false;
}
bool Haspath(int** maze,int n){
    int **ans=new int*[n];
    for(int i=0;i<n;i++){
        ans[i]=new int[n];
        for(int j=0;j<n;j++){
            ans[i][j]=0;
        }
    }
    PrintAllPath(maze,n,ans,0,0);
    return HaspathHelper(maze,n,ans,0,0);
}
int main(){
    int n;
    cout<<"Enter Maze size:";
    cin>>n;
    int **maze=new int*[n];
    cout<<"Enter the maze:"<<endl;
    for(int i=0;i<n;i++){
        maze[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            cin>>maze[i][j];
        }
        
    }
    cout<<Haspath(maze,n);
}