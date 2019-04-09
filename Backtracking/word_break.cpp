#include <bits/stdc++.h>
using namespace std;
/*
void word_break_util(string str, set<string> dict, int n, string res){
    for(int i=1;i<=n;i++){
        string prefix = str.substr(0, i);
        if(dict.find(prefix)!=dict.end()){
            if(i==n){
                res = res + prefix;
                cout<<res<<endl;
                return;
            }
            word_break_util(str.substr(i, n-i), dict, n-i, res+prefix+" ");
        }
    }
}
void word_break(string str, set<string> dict){
    int n = str.length();
    word_break_util(str, dict, n, "");
}
*/
void word_break_util(string str, set<string> dict, int n, string res){
    if(n==0){
        cout<<res<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        string prefix = str.substr(0, i);
        if(dict.find(prefix)!=dict.end()){
            word_break_util(str.substr(i, n-i), dict, n-i, res+" "+prefix);
        }
    }
}
void word_break(string str, set<string> dict){
    int n = str.length();
    word_break_util(str, dict, n, "");
}
int main() {
    string words[] = {"mobile","samsung","sam","sung", 
							"man","mango", "icecream", "and", 
							"go","i","love","ice","cream"};
    string str = "ilovesamsungmobile";
    int n = sizeof(words)/sizeof(words[0]);
	set<string> dict;
    for(int i=0;i<n;i++)
        dict.insert(words[i]);
	word_break(str, dict);
	return 0;
}