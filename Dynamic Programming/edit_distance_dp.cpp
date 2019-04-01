#include<bits/stdc++.h>
using namespace std;
int min(int a, int b, int c){
    return min(a, min(b, c));
}
int edit_distance(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    int table[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
                table[i][j] = j;
            else if(j==0)
                table[i][j] = i;
            else if(s1[i-1] == s2[j-1])
                table[i][j] = table[i-1][j-1];
            else{
                table[i][j] = 1 + min(table[i][j-1],        //insert
                                        table[i-1][j],      //remove
                                        table[i-1][j-1]);   //replace
            }
        }
    }
    return table[m][n];
}
int main(){
    string s1 = "sunday";
    string s2 = "saturday";
    int res = edit_distance(s1, s2);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(m*n)
//Space Complexity: O(m*n)