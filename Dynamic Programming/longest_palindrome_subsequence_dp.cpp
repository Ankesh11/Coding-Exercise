#include <bits/stdc++.h>
using namespace std;
int lps(string s){
    int n = s.length();
    int table[n][n] = {{0}};
    for(int i=0;i<n;i++)
        table[i][i] = 1;
    for(int k=2;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j = i+k-1;
            if(s[i]==s[j] && k==2)
                table[i][j] = 2;
            else if(s[i]==s[j])
                table[i][j] = 2 + table[i+1][j-1];
            else
                table[i][j] = max(table[i+1][j], table[i][j-1]);
        }
    }
    return table[0][n-1];
}

int main() {
	string s = "aabcdaa";
	int n = s.length();
	int res = lps(s);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(n^2)
//Space Complexity: O(n^2)