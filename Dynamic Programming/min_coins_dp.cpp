#include<bits/stdc++.h>
using namespace std;
int min_coins(int coins[], int n, int sum){
    int table[n][sum+1];
    for(int i=0;i<n;i++)
        for(int j=1;j<=sum;j++)
            table[i][j] = INT_MAX;
    for(int i=0;i<n;i++)
        table[i][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(i ==0 && j >= coins[i]){
                if(table[i][j-coins[i]] != INT_MAX)
                    table[i][j] = table[i][j-coins[i]]+1;
            }
            else if(i>0 && j >= coins[i]){
                table[i][j] = table[i-1][j];
                if(table[i][j-coins[i]] != INT_MAX)
                    table[i][j] = min(table[i-1][j], table[i][j-coins[i]]+1);
            }
        }
    }
    return table[n-1][sum];
}
int main(){
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 7;
    int res = min_coins(coins, n, sum);
    cout<<res<<endl;
    return 0;
}
//Time Complexity: O(n*sum)
//Space Complexity: O(n*sum)