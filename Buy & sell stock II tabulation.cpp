#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1, vector<long> (2, 0));
    long profit = 0;
    dp[n][0] = dp[n][1] = 0;
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<2; buy++)
    {
    if(buy){
        profit = max(-values[ind] + dp[ind+1][0], 
                          0 + dp[ind+1][1]);
        dp[ind][buy] = profit;
    }
    else{
        profit = max(values[ind] + dp[ind+1][1], 
                          0 + dp[ind+1][0]);
        dp[ind][buy] = profit;
    }
    
    }
    }
    return dp[0][1];
}
