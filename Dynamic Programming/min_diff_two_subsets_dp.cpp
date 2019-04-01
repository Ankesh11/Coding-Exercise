#include <bits/stdc++.h>
using namespace std;
int min_diff_subset(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    bool table[n+1][sum+1];
    for(int i=0;i<=n;i++)
        table[i][0] = true;
    for(int i=1;i<=sum;i++)
        table[0][i] = false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            table[i][j] = table[i-1][j];
            if(j >= arr[i-1])
                table[i][j] = table[i][j] | table[i-1][j-arr[i-1]];
        }
    }
    int min_diff;
    for(int i=sum/2;i>=0;i--){
        if(table[n][i] == true){
            min_diff = sum-2*i;
            break;
        }
    }
    return min_diff;
}
int main() {
	int arr[] = {2,6,11,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = min_diff_subset(arr, n);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(n*sum)
//Space Complexity: O(n*sum)