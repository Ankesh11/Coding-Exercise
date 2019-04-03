#include<bits/stdc++.h>
using namespace std;
#define N 9
bool next_unassigned(int grid[N][N], int &x, int &y){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 0){
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}
bool is_safe(int grid[N][N], int x, int y, int v){
    for(int i=0;i<N;i++){
        if(grid[x][i]==v || grid[i][y]==v)
            return false;
    }
    int begx = (x/3)*3;
    int begy = (y/3)*3;
    for(int i=begx; i<begx+3; i++){
        for(int j=begy; j<begy+3; j++){
            if(grid[i][j]==v)
                return false;
        }
    }
    return true;
}
void print_sol(int grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<"|";
        cout<<endl;
    }
}
bool solve_sudoku(int grid[N][N]){
    int x, y;
    if(next_unassigned(grid, x, y)==false)
        return true;
    for(int i=1;i<=N;i++){
        if(is_safe(grid, x, y, i)){
            grid[x][y] = i;
            if(solve_sudoku(grid)==true)
                return true;
            grid[x][y] = 0;
        }
    }
    return false;
}
void solve(int grid[N][N]){
    if(solve_sudoku(grid)==false){
        cout<<"Solution doesn't exist.";
        return;
    }
    print_sol(grid);
}
int main(){
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solve(grid);
    return 0;
}