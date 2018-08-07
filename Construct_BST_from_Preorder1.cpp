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
node *construct_bst_util(int pre[], int &prei, int low, int high, int n){
    if(prei>=n || low>high)
        return NULL;
    node *root = newnode(pre[prei]);
    prei++;
    if(low==high)
        return root;
    int i;
    for(i=low;i<=high;i++){
        if(pre[i] > root->data)
            break;
    }
    root->left = construct_bst_util(pre, prei, prei, i-1, n);
    root->right = construct_bst_util(pre, prei, i, high, n);
    return root;
}
node *construct_bst(int pre[], int n){
    int prei = 0;
    return construct_bst_util(pre, prei, 0, n-1, n);
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
