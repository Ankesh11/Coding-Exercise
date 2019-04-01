#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[], int n, int &start, int &end){
    int max_sum = 0;
    int sum = 0;
    int temp_start=0;
    end = -1;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            temp_start = i+1;
        }
        else{
            if(sum > max_sum){
                max_sum = sum;
                start = temp_start;
                end = i;
            }
        }
    }
    if(end != -1)
        return max_sum;
    //in case all elements are negative
    max_sum = arr[0];
    start = 0;
    end = 0;
    for(int i=1;i<n;i++){
        if(arr[i] > max_sum){
            max_sum = arr[i];
            start = i;
            end = i;
        }
    }
    return max_sum;
}
int max_sum_submatrix(int mat[100][100], int m, int n){
    int max_sum = INT_MIN;
    int sum, start, end;
    int res_left, res_right, res_top, res_bottom;
    int temp[m];
    for(int left=0;left<n;left++){
        memset(temp, 0, sizeof(temp));
        for(int right=left;right<n;right++){
            for(int i=0;i<m;i++)
                temp[i] += mat[i][right];
            
            sum = kadane(temp, m, start, end);
            if(sum > max_sum){
                max_sum = sum;
                res_left = left;
                res_right = right;
                res_top = start;
                res_bottom = end;
            } 
        }
    }
    cout<<"Top Left :("<<res_top<<", "<<res_left<<")"<<endl;
    cout<<"Bottom Right :("<<res_bottom<<", "<<res_right<<")"<<endl;
    return max_sum;
}
int main(){
    int mat[100][100] = {{1, 2, -1, -4, -20},  
                        {-8, -3, 4, 2, 1},  
                        {3, 8, 10, 1, 3},  
                        {-4, -1, 1, 7, -6}};
    int m = 4;
    int n = 5;
    int res = max_sum_submatrix(mat, m, n);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(ROW*COL^2)
//Space Complexity: O(ROW)