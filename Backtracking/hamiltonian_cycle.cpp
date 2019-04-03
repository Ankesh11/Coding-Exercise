#include <bits/stdc++.h>
#define V 5
using namespace std;
void print_path(vector<int> path){
    for(int i=0;i<path.size();i++)
        cout<<path[i]<<" ";
}
bool hamiltonion_cycle_util(int graph[V][V], vector<int> &path, bool added[V], int v){
    if(path.size()==V){
        if(graph[path[V-1]][0]==1)
            return true;
        return false;
    }
    for(int i=1;i<V;i++){
        if(graph[v][i]==1 && added[i]==false){
            path.push_back(i);
            added[i] = true;
            if(hamiltonion_cycle_util(graph, path, added, i)==true)
                return true;
            path.pop_back();
            added[i] = false;
        }
    }
    return false;
}
void hamiltonion_cycle(int graph[V][V]){
    vector<int> path;
    bool added[V] = {false};
    path.push_back(0);
    added[0]  = true;
    if(hamiltonion_cycle_util(graph, path, added, 0)==false){
        cout<<"Solution doesn't exist."<<endl;
        return;
    }
    print_path(path);
}
int main() {
	int graph[V][V] = {{0, 1, 0, 1, 0}, 
                      {1, 0, 1, 1, 1}, 
                      {0, 1, 0, 0, 1}, 
                      {1, 1, 0, 0, 1}, 
                      {0, 1, 1, 1, 0}, 
                     };
    hamiltonion_cycle(graph);
	return 0;
}