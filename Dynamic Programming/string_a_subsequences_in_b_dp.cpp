#include<bits/stdc++.h>
using namespace std;
int num_of_subsequences(string a, string b){
    int m = a.length();
    int n = b.length();
    int table[m+1][n+1];
    for(int i=0;i<=n;i++)
        table[0][i] = 1;
    for(int i=1;i<=m;i++)
        table[i][0] = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1])
                table[i][j] = table[i-1][j-1] + table[i][j-1];
            else
                table[i][j] = table[i][j-1];
        }
    }
    return table[m][n];
}
int main(){
    string a = "ab";
    string b = "abcdab";
    int res = num_of_subsequences(a, b);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(m*n)
//Space Complexity: O(m*n)