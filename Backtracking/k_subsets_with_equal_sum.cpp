#include <bits/stdc++.h>
#define N 9
using namespace std;
bool all_visited(bool visited[], int n){
    for(int i=0;i<n;i++){
        if(visited[i]==false)
            return false;
    }
    return true;
}
bool set_partition_util(int arr[], bool visited[], int n, int set_sum, int sum){
    if(all_visited(visited, n) && sum==set_sum)
        return true;
    if(sum == set_sum){
        return set_partition_util(arr, visited, n, set_sum, 0);
    }
    if(sum > set_sum)
        return false;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            sum += arr[i];
            visited[i]=true;
            if(set_partition_util(arr, visited, n, set_sum, sum)==true)
                return true;
            sum -= arr[i];
            visited[i] = false;
        }
    }
    return false;
}
void set_partition(int arr[], int n, int k){
    int total=0;
    for(int i=0;i<n;i++)
        total += arr[i];
    bool visited[n] = {false};
    if(total%k!=0 || set_partition_util(arr, visited, n, total/k, 0)==false){
        cout<<"Partition not possible.";
        return;
    }
    cout<<"Partition possible.";
}
int main() {
    int arr[] = {0,3,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
	set_partition(arr, n, k);
	return 0;
}