#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int n){
    int table[n] = {0};
    for(int i=0;i<n;i++)
        table[i] = 1;
    
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j] < arr[i])
                table[i] = max(table[i], table[j]+1);
        }
    }
    
    int res = 1;
    for(int i=0;i<n;i++)
        res = max(res, table[i]);
    return res;
}
int main() {
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = lis(arr, n);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(n^2)
//Space Complexity: O(n)