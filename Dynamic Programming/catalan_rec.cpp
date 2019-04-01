#include<bits/stdc++.h>
using namespace std;
long long int catalan(int n){
    if(n==0)
        return 1;
    long long int count = 0;
    for(int i=1;i<=n;i++)
        count += catalan(i-1)*catalan(n-i);
    return count;
}
int main(){
    clock_t t;
    t = clock();
    long long int res = catalan(20);
    t = clock() - t;
    double exet = (double)t/CLOCKS_PER_SEC;
    cout<<res<<endl;
    cout<<"Execution time: "<<exet<<endl;
    return 0;
}
//Time Complexity: O(4^n)