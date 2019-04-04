#include <bits/stdc++.h>
using namespace std;
void print_res(int map[26]){
    for(int i=0;i<26;i++){
        if(map[i]!=-1){
            cout<<(char)('A'+i)<<"-"<<map[i]<<endl;
        }
    }
}
bool is_valid(string op1, string op2, string res, int map[26]){
    int v1=0,v2=0,v3=0;
    for(int i=0;i<op1.length();i++)
        v1 = v1*10 + map[op1[i]-'A'];
    for(int i=0;i<op2.length();i++)
        v2 = v2*10 + map[op2[i]-'A'];
    for(int i=0;i<res.length();i++)
        v3 = v3*10 + map[res[i]-'A'];
    return (v1+v2 == v3);
}
bool is_safe(int map[26], int v){
    for(int i=0;i<26;i++){
        if(map[i]==v)
            return false;
    }
    return true;
}
bool crypt_puzzle_util(string op1, string op2, string res, vector<char> var, int map[26], int n){
    if(n==0){
        if(is_valid(op1, op2, res, map)==true)
            return true;
        return false;
    }
    char c = var[n-1];
    bool beg_pos = false;
    if(map[c-'A']==-2)
        beg_pos = true;
    for(int i=0;i<=9;i++){
        if(i==0 && beg_pos==true)
            continue;
        if(is_safe(map, i)){
            map[c-'A'] = i;
            if(crypt_puzzle_util(op1, op2, res, var, map, n-1)==true)
                return true;
            map[c-'A'] = -1;
            if(beg_pos==true)
                map[c-'A'] = -2;
        }
    }
    return false;
}

void crypt_puzzle(string op1, string op2, string res){
    int map[26] = {0};
    memset(map, 0, sizeof(map));
    for(int i=0;i<op1.length();i++)
        map[op1[i]-'A'] = -1;
    for(int i=0;i<op2.length();i++)
        map[op2[i]-'A'] = -1;
    for(int i=0;i<res.length();i++)
        map[res[i]-'A'] = -1;
    map[op1[0]-'A'] = -2;
    map[op2[0]-'A'] = -2;
    map[res[0]-'A'] = -2;
    vector<char> var;
    for(int i=0;i<26;i++){
        if(map[i] != 0)
            var.push_back('A'+i);
    }
    for(int i=0;i<26;i++){
        if(map[i]==0)
            map[i] = -1;
    }
    int n = var.size();
    if(crypt_puzzle_util(op1, op2, res, var, map, n)==false){
        cout<<"Solution doesn't exist.";
        return;
    }
    print_res(map);
}
int main() {
	string op1, op2, res;
	op1 = "SEND";
	op2 = "MORE";
	res = "MONEY";
	crypt_puzzle(op1, op2, res);
	return 0;
}