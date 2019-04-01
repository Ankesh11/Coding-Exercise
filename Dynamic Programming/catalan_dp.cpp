#include<bits/stdc++.h>
using namespace std;
long long int table[100];
long long int catalan(int n){
    if(n==0){
        table[0] = 1;
        return table[0];
    }
    if(table[n] !=0 )
        return table[n];
    table[n] = 0;
    for(int i=1;i<=n;i++)
        table[n] += catalan(i-1)*catalan(n-i);
    return table[n];
}
int main(){
    memset(table, 0, sizeof(table));
    clock_t t;
    t = clock();
    long long int res = catalan(20);
    t = clock() - t;
    double time_taken = (double)t/CLOCKS_PER_SEC;
    cout<<res<<endl;
    cout<<"Execution time: "<<time_taken<<endl;
    return 0;
}
//Time Complexity: O(n^2)