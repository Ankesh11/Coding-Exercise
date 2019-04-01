#include<bits/stdc++.h>
using namespace std;
int num_of_subsequences(string a, string b, int i, int j){
    if(i==0)
        return 1;
    if(j==0)
        return 0;
    if(a[i-1] == b[j-1])
        return num_of_subsequences(a, b, i-1, j-1)+num_of_subsequences(a, b, i, j-1);
    return num_of_subsequences(a, b, i, j-1);
}
int main(){
    string a = "ab";
    string b = "abcdab";
    int res = num_of_subsequences(a, b, a.length(), b.length());
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(2^n)