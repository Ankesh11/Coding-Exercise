#include<bits/stdc++.h>
#define N 8
using namespace std;
bool is_safe(int res[N][N], int row, int col){
    for(int i=0;i<col;i++){
        if(res[row][i] == 1)
            return false;
    }
    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(res[i][j] == 1)
            return false;
    }
    for(int i=row, j=col; i<N && j>=0; i++,j--){
        if(res[i][j] == 1)
            return false;
    }
    return true;
}
void print_res(int res[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
bool n_queen_util(int res[N][N], int col){
    if(col == N)
        return true;
    for(int i=0;i<N;i++){
        if(is_safe(res, i, col)){
            res[i][col] = 1;
            if(n_queen_util(res, col+1) == true)
                return true;
            res[i][col] = 0;
        }
    }
    return false;
}
void n_queen(){
    int res[N][N];
    memset(res, 0, sizeof(res));
    if(n_queen_util(res, 0) == false){
        cout<<"Solution doesn't exist.";
        return;
    }
    print_res(res);
}
int main(){
    n_queen();
    return 0;
}