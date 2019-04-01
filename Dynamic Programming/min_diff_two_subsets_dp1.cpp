#include <bits/stdc++.h>
using namespace std;
int min_diff_subset(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    bool table[sum+1], prev_state[sum+1];
    memset(table, false, sizeof(table));
    memset(prev_state, false, sizeof(prev_state));
    table[0] = true;
    prev_state[0] = true;
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= arr[i]){
                table[j] = table[j] | prev_state[j-arr[i]];
            }
        }
        memcpy(prev_state, table, sizeof(table));
    }
    int min_diff;
    for(int i=sum/2;i>=0;i--){
        if(table[i] == true){
            min_diff = sum - 2*i;
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
//Space Complexity: O(sum)