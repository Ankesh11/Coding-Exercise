#include <bits/stdc++.h>
using namespace std;
bool subset_sum(int arr[], int n,int sum){
    bool dp[sum+1];
    memset(dp, false, (sum+1)*sizeof(bool));
    dp[0] = true;
    for(int i=0;i<n;i++){
        for(int j=sum;j>=0;j--){
            if(j>=arr[i]){
                dp[j] = dp[j-arr[i]];
            }
        }
    }
    return dp[sum];
}
int main() {
	int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 9;
	bool res = subset_sum(arr, n, sum);
	cout<<res<<endl;
	return 0;
}
//TC: O(n*sum)
//SC: O(sum)