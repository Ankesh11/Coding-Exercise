#include <bits/stdc++.h>
using namespace std;
int min_diff_util(int arr[], int i, int sum, int total){
    if(i==0)
        return abs((total-sum)-sum);
    return min(min_diff_util(arr, i-1, sum+arr[i-1], total),
                min_diff_util(arr, i-1, sum, total));
}
int min_diff(int arr[], int n){
    int total = 0;
    for(int i=0;i<n;i++)
        total += arr[i];
    return min_diff_util(arr, n, 0, total);
}
int main() {
	//code
	int arr[] = {2,6,11,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = min_diff(arr, n);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(2^n)