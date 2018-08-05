#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int partition(int arr[],int beg,int end){
    int pivot = arr[end];
    int i=beg-1;
    for(int j=beg;j<end;j++){
        if(arr[j]<=pivot){
            swap(arr[j], arr[++i]);
        }
    }
    swap(arr[++i], arr[end]);
    return i;
}
int kth_smallest(int arr[],int beg,int end,int k){
    int q = partition(arr, beg, end);
    if(q==k-1)
        return arr[q];
    else if(k-1 < q)
        return kth_smallest(arr,beg, q-1, k);
    else
        return kth_smallest(arr,q+1, end, k);
}
int main(){
    int arr[]= {12, 3, 5, 7, 4, 19, 26, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int res = kth_smallest(arr, 0, n-1, k);
    cout<<res<<endl;
    return 0;
}
