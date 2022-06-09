// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
// You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. 
// Print 0, if a change isn't possible.

#include<bits/stdc++.h>
long f(int *a, int i, int tar, vector<vector<long>> &dp){
        if(i==0) return tar%a[i] == 0;
    
        if(dp[i][tar] != -1) return dp[i][tar];
    
        long pick = 0; long notpick;
        notpick = f(a, i-1, tar, dp);
        if(a[i]<=tar) pick = f(a, i, tar - a[i], dp);
    
        return dp[i][tar] = pick +notpick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    return f(denominations, n-1 ,value, dp); 
}
