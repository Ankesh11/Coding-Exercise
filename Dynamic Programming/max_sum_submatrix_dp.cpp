#include <bits/stdc++.h>
using namespace std;
int max_sum(int mat[100][100], int m, int n){
    int res_mat[m+1][n+1];
    for(int i=0;i<=n;i++)
        res_mat[0][i] = 0;
    for(int i=0;i<=m;i++)
        res_mat[i][0] = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            res_mat[i][j] = res_mat[i][j-1] + mat[i-1][j-1];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            res_mat[i][j] += res_mat[i-1][j];
    }
    int res = INT_MIN;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int bottom_left=0;bottom_left<n;bottom_left++){
                for(int top_right=0;top_right<m;top_right++){
                    res = max(res, res_mat[i][j] - res_mat[i][bottom_left] - res_mat[top_right][j] + res_mat[top_right][bottom_left]);
                }
            }
        }
    }
    return res;
}
int main(){
    int mat[100][100] = {{1, 2, -1, -4, -20},  
                        {-8, -3, 4, 2, 1},  
                        {3, 8, 10, 1, 3},  
                        {-4, -1, 1, 7, -6}};
    int m = 4;
    int n = 5;
    int res = max_sum(mat, m, n);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(ROW^2*COL^2)
//Space Complexity: O(ROW*COL)