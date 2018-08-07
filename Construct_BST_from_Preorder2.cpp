#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *newnode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node *construct_bst_util(int pre[], int &preindex, int key, int min, int max, int n){
    if(preindex>=n)
        return NULL;
    node *root = NULL;
    if(key>min && key<max){
        root = newnode(key);
        preindex++;
        root->left = construct_bst_util(pre, preindex, pre[preindex], min, key, n);
        root->right = construct_bst_util(pre, preindex, pre[preindex], key, max, n);
    }
    return root;
}
node *construct_bst(int pre[], int n){
    int preindex = 0;
    return construct_bst_util(pre, preindex, pre[preindex], INT_MIN, INT_MAX, n);
}
void inorder(node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0;i<n;i++)
        cin>>pre[i];
    node *root = construct_bst(pre,n);
    inorder(root);
    return 0;
}
//Time Complexity: O(n)