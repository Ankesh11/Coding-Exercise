#include<bits/stdc++.h>
#define N 6
using namespace std;
bool is_safe(int x, int y, int maze[N][N]){
    return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
}
void print_res(int res[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
bool rat_maze_util(int maze[N][N], int res[N][N], int x, int y){
    if(x==N-1 && y==N-1 && maze[x][y]==1){
        res[x][y] = 1;
        return true;
    }
    if(is_safe(x, y, maze)){
        res[x][y] = 1;
        if(rat_maze_util(maze, res, x+1, y)==true)//downward move
            return true;
        if(rat_maze_util(maze, res, x, y+1))//forward move
            return true;
        res[x][y] = 0;
    }
    return false;
}
void rat_maze(int maze[N][N]){
    int res[N][N];
    memset(res, 0, sizeof(res));
    if(rat_maze_util(maze, res, 0, 0) == false){
        cout<<"Solution doesn't exist."<<endl;
        return;
    }
    print_res(res);
}
int main(){
    int maze[N][N] = {{1,1,0,0,0,0},
                    {0,1,0,0,0,0},
                    {1,1,1,1,0,0},
                    {0,0,0,1,0,0},
                    {0,0,0,1,1,1},
                    {0,0,0,0,0,1}};
    rat_maze(maze);
    return 0;
}