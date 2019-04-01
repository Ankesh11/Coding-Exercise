#include <bits/stdc++.h>
using namespace std;
int min_jumps(int arr[], int i, int n){
    if(arr[i]==0)
        return INT_MAX;
    if(i>=n)
        return 0;
    int min_jump=INT_MAX;
    int temp_jump;
    for(int k=i+1;k<=i+arr[i];k++){
        temp_jump = min_jumps(arr, k, n);
        if(temp_jump!=INT_MAX)
            min_jump = min(min_jump, temp_jump+1);
    }
    return min_jump;
}
int main() {
	//code
	int arr[] = {2,3,1,1,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = min_jumps(arr, 0, n-1);
	cout<<res<<endl;
	return 0;
}