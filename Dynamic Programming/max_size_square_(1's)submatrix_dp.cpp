#include <bits/stdc++.h>
#define m 6
#define n 5
using namespace std;
int min(int a, int b, int c){
    return min(a, min(b, c));
}
int max_square_matrix(int mat[m][n]){
    int max_size = 0;
    int **res_mat = new int*[m];
    for(int i=0;i<m;i++)
        res_mat[i] = new int[n];
    for(int i=0;i<n;i++)
        res_mat[0][i] = mat[0][i];
    for(int i=0;i<m;i++)
        res_mat[i][0] = mat[i][0];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(mat[i][j]==1){
                res_mat[i][j] = 1 + min(res_mat[i-1][j], res_mat[i][j-1], res_mat[i-1][j-1]);
                max_size = max(max_size, res_mat[i][j]);
            }
            else
                res_mat[i][j] = 0;
        }
    }
    return max_size;
}
int main() {
    
	int mat[m][n] = {{0, 1, 1, 0, 1},
                     {1, 1, 0, 1, 0}, 
                     {0, 1, 1, 1, 0},
                     {1, 1, 1, 1, 0},
                     {1, 1, 1, 1, 1},
                     {0, 0, 0, 0, 0}};
	clock_t t;
	t = clock();
	int res = max_square_matrix(mat);
	t = clock()-t;
	double time_taken = (double)t/CLOCKS_PER_SEC;
    cout<<res<<endl;
	cout<<"Execution time: "<<time_taken<<endl;
	return 0;
}
//Time Complexity: O(ROW*COL)
//Space Complexity: O(ROW*COL)