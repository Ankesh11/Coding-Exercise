#include<bits/stdc++.h>
#define N 8
using namespace std;
bool is_safe(int x, int y, int grid[N][N]){
    return (x>=0 && x<N && y>=0 && y<N && grid[x][y]==-1);
}
void print_res(int grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}
bool knights_tour_util(int grid[N][N], int x, int y, int moves, int x_move[], int y_move[]){
    if(moves == N*N)
        return true;
    for(int i=0;i<8;i++){
        int next_x = x + x_move[i];
        int next_y = y +y_move[i];
        if(is_safe(next_x, next_y, grid)){
            grid[next_x][next_y] = moves;
            if(knights_tour_util(grid, next_x, next_y, moves+1, x_move, y_move)==true){
                return true;
            }
            else
                grid[next_x][next_y] = -1;
        }
    }
    return false;
}
void knights_tour(){
    int grid[N][N];
    memset(grid, -1, sizeof(grid));
    int xmove[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int ymove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    grid[0][0] = 0;
    if(knights_tour_util(grid, 0, 0, 1, xmove, ymove) == false){
        cout<<"Solution doesn't exist\n";
        return;
    }
    print_res(grid);
}
int main(){
    knights_tour();
    return 0;
}