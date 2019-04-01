#include <bits/stdc++.h>
using namespace std;
string lngst_plndrm_sbstr(string s){
    int maxlength = 1;
    int start = 0;
    int p, q;
    int n = s.length();
    for(int i=1;i<n;i++){
        //for even length substring
        p = i-1;
        q = i;
        while(p>=0 && q<n && s[p]==s[q]){
            p--;
            q++;
        }
        if(q-p-1 > maxlength){
            maxlength = q-p-1;
            start = p+1;
        }
        //for odd length substring
        p = i-1;
        q = i+1;
        while(p>=0 && q<n && s[p]==s[q]){
            p--;
            q++;
        }
        if(q-p-1 > maxlength){
            maxlength = q-p-1;
            start = p+1;
        }
    }
    return s.substr(start, maxlength);
}
int main() {
	string s = "cabccbaa";
	string res = lngst_plndrm_sbstr(s);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(n^2)