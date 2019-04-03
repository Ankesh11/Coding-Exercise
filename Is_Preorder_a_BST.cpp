#include <bits/stdc++.h>
using namespace std;
bool is_preorder_bst(int pre[], int n){
    stack<int> s;
    int root=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre[i]<root)
            return false;
        while(!s.empty() && s.top()<pre[i]){
            root = s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0;i<n;i++)
        cin>>pre[i];
    cout<<is_preorder_bst(pre, n)<<endl;
}
//Time Complexity: O(n)..