#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
void floyds_warshall(int adj_mat[100][100], int n){
    int dist[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = adj_mat[i][j];
        }
    }

    for(int k=0;k<n-1;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    if(dist[i][k]+dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == INF)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int adj_mat[100][100] = { {0,   5,  INF, 10}, 
                            {INF, 0,   3, INF}, 
                            {INF, INF, 0,   1}, 
                            {INF, INF, INF, 0}};
    int n = 4;
    floyds_warshall(adj_mat, n);
    return 0;
}
//Time Complexity: O(n^3)
//Space Complexity: O(n^2)