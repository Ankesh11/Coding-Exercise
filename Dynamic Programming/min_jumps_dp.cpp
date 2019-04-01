#include <bits/stdc++.h>
using namespace std;
int min_jumps(int arr[], int n){
    int table[n];
    if(n==0 || arr[0]==0)
        return INT_MAX;
    table[0] = 0;
    for(int i=1; i<n; i++){
        table[i] = INT_MAX-1;
        for(int j=0; j<i; j++){
            if(j+arr[j] >= i){
                table[i] = min(table[i], table[j]+1);
            }
        }
    }
    return table[n-1];
}
int main() {
	//code
	int arr[] = {2,3,1,1,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = min_jumps(arr, n);
	cout<<res<<endl;
	return 0;
}