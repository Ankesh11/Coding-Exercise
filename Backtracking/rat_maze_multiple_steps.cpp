#include <bits/stdc++.h>
using namespace std;
#define N 4
bool is_safe(int maze[N][N], int i, int j){
    return (maze[i][j]!=0 && i>=0 && i<N && j>=0 && j<N);
}
void print_sol(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
}
bool solve_maze(int maze[N][N], int sol[N][N], int i, int j){
    if(i==N-1 && j==N-1){
        if(maze[i][j]!=0){
            sol[i][j] = 1;
            return true;
        }
        return false;
    }
    if(is_safe(maze, i, j)){
        sol[i][j] = 1;
        int k = maze[i][j];
        for(int s=1;s<=k;s++){
            if(solve_maze(maze, sol, i, j+s)==true)
                return true;
            if(solve_maze(maze, sol, i+s, j)==true)
                return true;
        }
        sol[i][j] = 0;
    }
    return false;
}
void solve(int maze[N][N]){
    int sol[N][N];
    memset(sol, 0, sizeof(sol));
    if(solve_maze(maze, sol, 0, 0)==false){
        cout<<"Solution doesn't exist.";
        return;
    }
    print_sol(sol);
}
int main() {
	int maze[N][N] = { {2, 1, 0, 0},
                        {3, 0, 0, 1},
                        {0, 1, 0, 1},
                        {0, 0, 0, 1}};
    solve(maze);
	return 0;
}