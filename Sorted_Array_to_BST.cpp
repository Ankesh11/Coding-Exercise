#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *new_node(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
node *construct_bst_util(int arr[], int low, int high){
    if(low>high)
        return NULL;
    int mid = (low+high)/2;
    node *root = NULL;
    root = new_node(arr[mid]);
    root->left = construct_bst_util(arr, low, mid-1);
    root->right = construct_bst_util(arr, mid+1, high);
    return root;
}
node *construct_bst(int arr[], int n){
    return construct_bst_util(arr, 0, n-1);
}
void inorder(node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node *root = construct_bst(arr,n);
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(root);
    return 0;
}
//Time Complexity: O(n)
