#include <bits/stdc++.h>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *TakeInputLeveWise()
{
    int rootData;
    cout << "Enter Root data:" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pending;
    pending.push(root);
    while (!pending.empty())
    {
        TreeNode<int> *front = pending.front();
        pending.pop();
        int n;
        cout << "Enter Number of children of " << front->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter the " << i << "'th child of " << front->data << ": ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}
void PrintLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pending;
    pending.push(root);
    pending.push(NULL);
    while (!pending.empty())
    {
        TreeNode<int> *front = pending.front();
        pending.pop();
        if(front==NULL){
            cout<<endl;
            continue;
        }
        // cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            pending.push(front->children[i]);
        }
        if (!pending.empty())
        {
            pending.push(NULL);
        }
        
        
    }
}
void ReplaceWithDepth(TreeNode<int>* root,int depth){
    if(root==NULL){
        return;
    }
    root->data=depth;   
    for (int i = 0; i < root->children.size(); i++)
    {
        ReplaceWithDepth(root->children[i],depth+1);
    }
    return;

}
int main(){
    TreeNode<int>* root=TakeInputLeveWise();
    ReplaceWithDepth(root,0);
    PrintLevelWise(root);
}