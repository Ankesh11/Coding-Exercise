#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int i, int k){
    if(i==0)
        return (arr[i]<k?1:0);
    if(arr[i] >= k)
        return lis(arr, i-1, k);
    return max(lis(arr, i-1, arr[i])+1,
                lis(arr, i-1, k));
}

int main() {
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = lis(arr, n-1, INT_MAX);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(2^n)