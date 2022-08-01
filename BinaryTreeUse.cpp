#include <bits/stdc++.h>
#include "BinaryTree.h"
#include"Node.h"
using namespace std;

void printLL(Node<int> *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}
void PrintBT(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data << " ";
    }
    cout << endl;

    PrintBT(root->left);

    PrintBT(root->right);
}
// Take input recursive
BinaryTree<int> *TakeInputR()
{
    int rootData;
    cout << "Enter rootData: ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    root->left = TakeInputR();
    root->right = TakeInputR();
    return root;
}
// take input level wise
BinaryTree<int> *TakeInput()
{
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    queue<BinaryTree<int> *> pending;
    pending.push(root);
    while (!pending.empty())
    {
        BinaryTree<int> *front = pending.front();
        pending.pop();
        int l, r;
        cout << "Left child data of " << front->data << ":";
        cin >> l;
        if (l != -1)
        {
            BinaryTree<int> *lt = new BinaryTree<int>(l);
            pending.push(lt);
            front->left = lt;
        }
        cout << "Right child data of " << front->data << ":";
        cin >> r;
        if (r != -1)
        {
            BinaryTree<int> *rt = new BinaryTree<int>(r);
            pending.push(rt);
            front->right = rt;
        }
    }
    return root;
}
int coutnNode(BinaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    int ans1 = coutnNode(root->left);
    int ans2 = coutnNode(root->right);
    return ans1 + ans2 + 1;
}
bool FindNode(BinaryTree<int> *root, int node)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == node)
    {
        return true;
    }
    return (FindNode(root->left, node) || FindNode(root->right, node));
}
int HeightOfTree(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(HeightOfTree(root->left), HeightOfTree(root->right));
}
void Mirror(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    BinaryTree<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    Mirror(root->left);
    Mirror(root->right);
    return;
}
// Traversal
void inorder(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preOrder(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
// Build Binary Tree
BinaryTree<int> *BuildTreehelper(int *in, int *pr, int inS, int inE, int prS, int prE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = pr[prS];
    int rootIdx = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIdx = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIdx - 1;
    int lprS = prS + 1;
    int lprE = lprS + linE - linS;
    int rprS = lprE + 1;
    int rprE = prE;
    int rinS = rootIdx + 1;
    int rinE = inE;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    root->left = BuildTreehelper(in, pr, linS, linE, lprS, lprE);
    root->right = BuildTreehelper(in, pr, rinS, rinE, rprS, rprE);
    return root;
}
BinaryTree<int> *BuildTree(int *in, int *pre, int size)
{

    return BuildTreehelper(in, pre, 0, size - 1, 0, size - 1);
}
// Diameter
int Diameter(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int op1 = HeightOfTree(root->left) + HeightOfTree(root->right);
    int op2 = Diameter(root->left);
    int op3 = Diameter(root->right);
    return max(op1, max(op2, op3));
}
// Binary Tree to linked list level wise
vector<Node<int> *> BtToLL(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<Node<int> *> ans;
    queue<BinaryTree<int> *> pending;
    pending.push(root);
    pending.push(NULL);
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while (!pending.empty())
    {
        BinaryTree<int> *front = pending.front();
        pending.pop();
        if (front == NULL)
        {
            if (!pending.empty())
            {
                pending.push(NULL);
            }
            ans.push_back(head);
            head = NULL;
            tail = NULL;
        }

        Node<int> *l = new Node(front->data);
        if (head == NULL)
        {
            head = l;
            tail = l;
        }
        else
        {
            tail->next = l;
            tail = tail->next;
        }
        if (front->left != NULL)
        {
            pending.push(front->left);
        }
        if (front->right != NULL)
        {
            pending.push(front->right);
        }
    }
    return ans;
}
//  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    // BinaryTree<int> *root = TakeInput();
    //  new BinaryTree<int>(1);
    // BinaryTree<int> *n1 = new BinaryTree<int>(2);
    // BinaryTree<int> *n2 = new BinaryTree<int>(3);
    // root->left = n1;
    // root->right = n2;
    // PrintBT(root);
    // cout<<endl<<"Number of node: "<<coutnNode(root)<<endl;
    // // cout<<FindNode(root,10);
    // cout<<"Height:"<<HeightOfTree(root)<<endl;
    // Mirror(root);
    // PrintBT(root);
    /* cout << endl
          << "inorder:";
     inorder(root);
     cout << endl
          << "preOrder:";
     preOrder(root);
     cout << endl
          << "postOrder:";
     postOrder(root);
     */
    /*
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    BinaryTree<int> *root = BuildTree(in, pre, 9);
    PrintBT(root);
    */
    BinaryTree<int> *root = TakeInput();
    vector<Node<int> *> ans = BtToLL(root);
    for (int i = 0; i < ans.size(); i++)
    {
        printLL(ans[i]);
    }

    delete root;
}