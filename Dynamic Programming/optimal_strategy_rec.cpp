#include <bits/stdc++.h>
using namespace std;
int optimal_strategy(int arr[], int i, int j){
    if(i==j)
        return arr[i];
    if(i+1==j)
        return max(arr[i], arr[j]);
    return max(arr[i] + min(optimal_strategy(arr, i+2,j), optimal_strategy(arr, i+1, j-1)),
                arr[j] + min(optimal_strategy(arr, i+1, j-1), optimal_strategy(arr, i, j-2)));
}
int main() {
	int arr[] = {5,3,7,10,2,6,8,45,23,5,5,8,2,3,6,7,5,74,5,74,5,4,2,3,85,12,5,4,87,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	clock_t t;
	t = clock();
	int res = optimal_strategy(arr, 0, n-1);
	t = clock()-t;
	double time_taken = (double)t/CLOCKS_PER_SEC;
	cout<<res<<endl;
	cout<<"Execution time: "<<time_taken<<endl;
	return 0;
}