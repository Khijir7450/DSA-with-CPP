#include <bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;
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
void leftNode(BinaryTree<int>* root,vector<int>& ans){
    if(root==NULL ||(root->left==NULL && root->right==NULL)) return;
    if(root->left==NULL && root->right!=NULL){
        ans.push_back(root->data);
        leftNode(root->right,ans);
    }
    else{
        ans.push_back(root->data);
        leftNode(root->left,ans);
    }
}
void leafNode(BinaryTree<int>* root, vector<int>&ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    else{
        leafNode(root->left,ans);
        leafNode(root->right,ans);
    }
}
void rightNode(BinaryTree<int>* root,vector<int>& ans){
    if(root==NULL||(root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left!=NULL && root->right==NULL){
        ;
        rightNode(root->left,ans);
        ans.push_back(root->data);
    }
    else{
        
        rightNode(root->right,ans);
        ans.push_back(root->data);
    }
}
vector<int> Boundary(BinaryTree<int>* root){
    vector<int>ans;
    leftNode(root,ans);
    leafNode(root,ans);
    rightNode(root,ans);
    return ans;
}
int main(){
    BinaryTree<int>* root=TakeInput();
    vector<int> ans=Boundary(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
    

}