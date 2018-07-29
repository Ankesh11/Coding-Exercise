#include<bits/stdc++.h>
using namespace std;
int peak_finding(int arr[],int beg,int end,int n){
    int mid = (beg+end)/2;
    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
        return mid;
	
    else if(mid>0 && arr[mid-1]>arr[mid])
        return peak_finding(arr, beg, mid-1, n);
	
    else if(mid<n-1 || arr[mid+1]>arr[mid])
        return peak_finding(arr, mid+1, end, n);
}
int main(){
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int n = sizeof(arr)/sizeof(arr[0]);
    int peak = peak_finding(arr, 0, n-1, n);
    cout<<peak<<endl;
    return 0;
}
//Time Complexity: O(logn)
//There will always be a peak in an array
