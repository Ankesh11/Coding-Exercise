#include<bits/stdc++.h>
using namespace std;
#define MAX 100
struct Output{
    int val;
    int row;
    int col;
};
int find_max(int arr[][MAX], int row, int col, int &max){
    int max_index=0;
    for(int i=0;i<row;i++){
        if(arr[i][col]>max){
            max = arr[i][col];
            max_index = i;
        }
    }
    return max_index;
}
Output peak_finding(int arr[][MAX], int row, int col, int mid){
    int max = 0;
    int max_index = find_max(arr, row, mid, max);

    if((mid==0 || arr[max_index][mid-1]<=arr[max_index][mid]) && (mid==col-1 ||
    arr[max_index][mid+1]<=arr[max_index][mid]))
        return Output{max, max_index, mid};

    else if(mid>0 && arr[max_index][mid-1]>arr[max_index][mid])
        return peak_finding(arr, row, col, mid - ceil(mid/2.0));

    else if(mid<col-1 && arr[max_index][mid+1] > arr[max_index][mid])
        return peak_finding(arr, row, col, mid + ceil(mid/2.0));
}
int main(){
    int arr[][MAX] = {{ 10, 8, 10, 10 },
                     { 14, 13, 12, 11 },
                     { 15, 9, 11, 21 },
                     { 16, 17, 19, 20 }};
    int rows = 4, columns = 4;
    Output res = peak_finding(arr, rows, columns, columns/2);
    cout<<res.val<<" ("<<res.row<<","<<res.col<<")"<<endl;
    return 0;
}
