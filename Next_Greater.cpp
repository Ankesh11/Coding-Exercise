#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    stack<int> stk;
    stk.push(arr[0]);
    for(int i=1;i<n;i++){
        if(stk.empty()){
            stk.push(arr[i]);
            continue;
        }
        while(!stk.empty() && stk.top()<arr[i]){
            cout<<stk.top()<<" "<<arr[i]<<endl;
            stk.pop();
        }
        stk.push(arr[i]);
    }
    while(!stk.empty()){
        cout<<stk.top()<<" "<<-1<<endl;
        stk.pop();
    }
    return 0;
}
//Time Complexity: O(n)
