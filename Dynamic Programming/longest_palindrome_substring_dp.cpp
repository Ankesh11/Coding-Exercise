#include <bits/stdc++.h>
using namespace std;
int lps(string s){
    int max_length = 1;
    int start = 0;
    int n = s.length();
    bool table[n][n] = {{false}};
    for(int i=0;i<n;i++)
        table[i][i] = true;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            table[i][i+1] = true;
            max_length = 2;
            start = i;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j = i+k-1;
            if(table[i+1][j-1]==true && s[i]==s[j]){
                table[i][j] = true;
                max_length = k;
                start = i;
            }
        }
    }
    cout<<s.substr(start, max_length)<<endl;
    return max_length;
}
int main() {
	string s = "cabccbaa";
    int res = lps(s);
    cout<<res<<endl;
	return 0;
}
//Time Complexity: O(n^2)
//Space Complexity: O(n^2)