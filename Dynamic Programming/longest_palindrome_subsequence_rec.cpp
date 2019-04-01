#include<bits/stdc++.h>
using namespace std;
int lps(string s, int i, int j){
    if(i>j)
        return 0;
    if(i==j)
        return 1;
    if(s[i] == s[j])
        return 2 + lps(s, i+1, j-1);
    return max(lps(s, i+1, j), lps(s, i, j-1));
}
int main(){
    string s = "aabcdaa";
    int res = lps(s, 0, s.length()-1);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(2^n)