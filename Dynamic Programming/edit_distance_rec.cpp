#include<bits/stdc++.h>
using namespace std;
int min(int a, int b, int c){return min(a, min(b, c));}
int edit_distance(string s1, string s2, int m, int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(s1[m-1] == s2[n-1])
        return edit_distance(s1, s2, m-1, n-1);
    return 1 + min(edit_distance(s1, s2, m-1, n),
                    edit_distance(s1, s2, m-1, n-1),
                    edit_distance(s1, s2, m, n-1));

}
int main(){
    string s1 = "sunday";
    string s2 = "saturday";
    int res = edit_distance(s1, s2, s1.length(), s2.length());
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(3^m)