#include<bits/stdc++.h>
using namespace std;
int min_coins(int coins[], int n, int sum){
    if(sum == 0)
        return 0;
    int res = INT_MAX;
    for(int i=0;i<n;i++){
        if(coins[i] <= sum){
            int temp = min_coins(coins, n, sum-coins[i]);
            res = min(res, temp+1);
        }
    }
    return res;
}
int main(){
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 11;
    int res = min_coins(coins, n, sum);
    cout<<res<<endl;
    return 0;
}