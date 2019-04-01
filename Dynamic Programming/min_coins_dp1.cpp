#include<bits/stdc++.h>
using namespace std;
int min_coins(int coins[], int n, int sum){
    int table[sum+1];
    for(int i=1;i<=sum;i++)
        table[i] = INT_MAX;
    table[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= coins[i]){
                if(table[j-coins[i]] != INT_MAX)
                    table[j] = min(table[j], table[j-coins[i]]+1);
            }
        }
    }
    return table[sum];
}
int main(){
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 13;
    int res = min_coins(coins, n, sum);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(n*sum)
//Space Complexity: O(sum)