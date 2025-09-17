#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *TakeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: ";
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
        for (int i = 1; i <= n; i++)
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
pair<int, int> SecondLargestElement(TreeNode<int> *root)
{
    pair<int, int> ans;
    ans.first = root->data;
    ans.second = INT_MIN;
    pair<int, int> temp;
    for (int i = 0; i < root->children.size(); i++)
    {
        temp = SecondLargestElement(root->children[i]);
        // ans.first = max(ans.first, temp.first);
        if (temp.first > ans.first)
        {

            ans.second = max(ans.first, temp.second);
            ans.first=temp.first;
        }
        else
        {
            ans.second=max(ans.second,temp.first);
        }
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = TakeInputLevelWise();
    pair<int,int> ans=SecondLargestElement(root);
    cout<<"Largest: "<<ans.first<<endl<<"Second Largest: "<<ans.second;
}
