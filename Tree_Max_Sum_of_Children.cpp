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
pair<int, TreeNode<int> *> NodeHavingMaxChildSum(TreeNode<int> *root)
{
    TreeNode<int> *node = root;
    int maxsum = node->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxsum += root->children[i]->data;
    }
    pair<int, TreeNode<int> *> ans;
    ans.first = maxsum;
    ans.second = root;
    pair<int, TreeNode<int> *> temp;
    for (int i = 0; i < root->children.size(); i++)
    {

        temp = NodeHavingMaxChildSum(root->children[i]);
        if (temp.first > ans.first)
        {
            ans.first = temp.first;
            ans.second = root->children[i];
        }
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = TakeInputLeveWise();
    pair<int, TreeNode<int> *> ans = NodeHavingMaxChildSum(root);
    cout << ans.second->data << ":" << ans.first;
}