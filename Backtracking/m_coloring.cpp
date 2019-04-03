#include<bits/stdc++.h>
#define V 4
using namespace std;
bool is_safe(int graph[V][V], int color[V], int v, int c){
    for(int i=0;i<V;i++){
        if(graph[v][i]==1 && color[i]==c)
            return false;
    }
    return true;
}

bool m_coloring_util(int graph[V][V], int m, int color[V], int v){
    if(v == V)
        return true;
    for(int i=1;i<=m;i++){
        if(is_safe(graph, color, v, i)){
            color[v] = i;
            if(m_coloring_util(graph, m, color, v+1)==true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}
void m_coloring(int graph[V][V], int m){
    int color[V] = {0};
    if(m_coloring_util(graph, m, color, 0)==false){
        cout<<"Solution not possible."<<endl;
        return;
    }
    for(int i=0;i<V;i++)
        cout<<color[i]<<" ";
}
int main(){
    int graph[V][V] = {{0, 1, 1, 1}, 
                        {1, 0, 1, 0}, 
                        {1, 1, 0, 1}, 
                        {1, 0, 1, 0},};
    int m = 3;
    m_coloring(graph, m);
    return 0;
}