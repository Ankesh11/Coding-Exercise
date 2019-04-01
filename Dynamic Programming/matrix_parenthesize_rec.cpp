#include<bits/stdc++.h>
using namespace std;
int matrix_parenthesize(int p[], int i, int j){
    if(i==j)
        return 0;
    int res = INT_MAX;
    for(int k=i;k<j;k++){
        res = min(res, matrix_parenthesize(p, i,k)+
                        matrix_parenthesize(p, k+1, j)+
                        p[i-1]*p[k]*p[j]);
    }
    return res;
}
int main(){
    int p[] = {40, 20, 30, 10, 30};
    int n = sizeof(p)/sizeof(p[0]);
    int res = matrix_parenthesize(p, 1, n-1);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(2^n)