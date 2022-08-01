#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
void PrintTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        PrintTree(root->children[i]);
    }
}
void PrintLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pending;
    pending.push(root);
    while (!pending.empty())
    {
        TreeNode<int> *front = pending.front();
        pending.pop();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pending.push(front->children[i]);
        }
        cout << endl;
    }
}
TreeNode<int> *TakeInput()
{
    int rootData;
    cout << "Enter root data:";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter Number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = TakeInput();
        root->children.push_back(child);
    }
    return root;
}
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
int countNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNode(root->children[i]);
    }
    return ans;
}
int Height(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.empty())
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = max(Height(root->children[i]), ans);
    }
    return ans + 1;
}
void PrintAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL || k == 0)
    {
        return;
    }

    if (k == 1 && root->children.size() != 0)
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ",";
        }
    }
    else
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            PrintAtLevelK(root->children[i], k - 1);
        }
    }
}
int CountLeafs(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += CountLeafs(root->children[i]);
    }
    return ans;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
// delete
void Delete(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        Delete(root->children[i]);
    }
    delete root;
}
int main()
{
    // TreeNode<int>* root=new TreeNode<int>(1);
    // TreeNode<int>* node1=new TreeNode<int>(2);
    // TreeNode<int>* node2=new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int> *root = TakeInputLeveWise();
    PrintLevelWise(root);
    // cout << endl
    //      << "Height of tree is: " << Height(root) << endl;
    PrintAtLevelK(root, 3);
    cout << endl;
    cout << "Number of Leaf node: " << CountLeafs(root);
    Delete(root); 
    // we can use destructor
    delete root; 

}