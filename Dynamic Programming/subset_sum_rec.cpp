#include <bits/stdc++.h>
using namespace std;
bool subset_sum(int arr[], int i, int n,int sum){
    if(sum == 0)
        return true;
    if(i==n)
        return false;
    if(arr[i] > sum)
        return subset_sum(arr, i+1, n, sum);
    return (subset_sum(arr, i+1, n, sum-arr[i]) || 
            subset_sum(arr, i+1, n, sum));
}
int main() {
	int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = -1;
	bool res = subset_sum(arr, 0, n, sum);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(2^n)