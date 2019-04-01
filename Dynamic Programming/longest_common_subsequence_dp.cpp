#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    int table[m+1][n+1];
    for(int i=0;i<=m;i++)
        table[i][0] = 0;
    for(int i=0;i<=n;i++)
        table[0][i] = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1])
                table[i][j] = 1+table[i-1][j-1];
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
    //printing lcs
    stack<char> stk;
    int i=m, j=n;
    while(i!=0 && j!=0){
        if(s1[i-1]==s2[j-1]){
            stk.push(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(table[i-1][j] > table[i][j-1])
                i--;
            else
                j--;
        }
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
    cout<<endl;
    return table[m][n];
}
int main() {
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	int res = lcs(s1, s2);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
