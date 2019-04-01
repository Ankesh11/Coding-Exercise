#include <bits/stdc++.h>
using namespace std;
bool subset_sum(int arr[], int n,int sum){
    bool dp[n][sum+1];
    memset(dp, false, n*(sum+1)*sizeof(bool));
    for(int i=0;i<n;i++)
        dp[i][0] = true;
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum; j++){
            if(i==0){
                if(j == arr[i])
                    dp[i][j] = true;
            }
            else{
                bool temp1 = dp[i-1][j];
                bool temp2 = false;
                if(j>=arr[i])
                    temp2 = dp[i-1][j- arr[i]];
                dp[i][j] = (temp1 || temp2);
            }
        }
    }
    return dp[n-1][sum];
}
int main() {
	int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 12;
	bool res = subset_sum(arr, n, sum);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(n*sum)
//Space Complexity: O(n*sum)