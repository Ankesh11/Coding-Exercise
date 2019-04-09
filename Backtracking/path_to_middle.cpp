#include <bits/stdc++.h>
#define N 9
using namespace std;

bool is_safe(int mat[N][N], int sol[N][N], int x, int y){
    return (x>=0 && x<N && y>=0 && y<N && mat[x][y]!=0 && sol[x][y]==0);
}
void print_sol(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(sol[i][j]==0)
                cout<<setw(2)<<"-"<<" ";
            else
                cout<<setw(2)<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool find_path_util(int mat[N][N], int sol[N][N], int x, int y, int &count){
    if(x==N/2 && y==N/2){
        sol[x][y] = count;
        return true;
    }
    if(is_safe(mat, sol, x, y)){
        sol[x][y] = count;
        count++;
        int k = mat[x][y];
        if(find_path_util(mat, sol, x+k, y, count)==true)
            return true;
        if(find_path_util(mat, sol, x-k, y, count)==true)
            return true;
        if(find_path_util(mat, sol, x, y+k, count)==true)
            return true;
        if(find_path_util(mat, sol, x, y-k, count)==true)
            return true;
        sol[x][y] = 0;
        count--;
    }
    return false;
}
void find_path(int mat[N][N]){
    int sol[N][N], count=1;
    memset(sol, 0, sizeof(sol));
    if(find_path_util(mat, sol, 0, 0, count)==false){
        cout<<"Solution doesn't exist.";
        return;
    }
    print_sol(sol);
}
int main() {
	int mat[N][N] = { 
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 }, 
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 }, 
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 }, 
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 }, 
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 }, 
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 }, 
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 }, 
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 }};
    find_path(mat);
	return 0;
}