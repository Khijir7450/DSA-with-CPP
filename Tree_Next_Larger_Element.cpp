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
int NextLargerElement(TreeNode<int> *root, int k)
{

    int ans=INT_MAX;
    if(root==NULL){
        return 0;
    }

    if (root->data > k)
    {
        ans=root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int ans1=NextLargerElement(root->children[i],k);
        ans=min(ans,ans1);
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = TakeInputLeveWise();
    int k;
    cout << "Enter a number which next larger element you want to search:" << endl;
    cin >> k;
    cout<<"Next larger element: "<<NextLargerElement(root,k);
}