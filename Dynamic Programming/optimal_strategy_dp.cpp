#include <bits/stdc++.h>
using namespace std;
//top-down approach
int optimal_strategy_util(int arr[], int i, int j, int **table){
    if(table[i][j]!=-1)
        return table[i][j];
    if(i+1==j){
        table[i][j] = max(arr[i],arr[j]);
        return table[i][j];
    }
    table[i][j] = max( arr[i] + min(optimal_strategy_util(arr,i+2,j,table),
                                    optimal_strategy_util(arr,i+1,j-1,table)),
                        arr[j] + min(optimal_strategy_util(arr,i+1,j-1,table),
                                    optimal_strategy_util(arr, i, j-2, table)));
    return table[i][j];
}
int optimal_strategy(int arr[], int n){
    int **table = new int*[n];
    for(int i=0;i<n;i++)
        table[i] = new int[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                table[i][j] = arr[i];
            else
                table[i][j] = -1;
        }
    }
    return optimal_strategy_util(arr, 0, n-1, table);
}
int main() {
	//code
	int arr[] = {5,3,7,10,2,6,8,45,23,5,5,8,2,3,6,7,5,74,5,74,5,4,2,3,85,12,5,4,87,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	clock_t t;
	t = clock();
	int res = optimal_strategy(arr, n);
	t = clock()-t;
	double time_taken = (double)t/CLOCKS_PER_SEC;
	cout<<res<<endl;
	cout<<"Execution time: "<<time_taken<<endl;
	return 0;
}