int f(vector<int> &wt, vector<int> &v, int i, int maxW, vector<vector<int>> &dp){
//     represnt in indexes
    if(i==0){
        if(wt[i]<=maxW) dp[i][maxW] = v[i];
        else dp[i][maxW] = 0;
    }
    if(dp[i][maxW]!=-1) return dp[i][maxW];
//     do all stuffs
    int pick = 0; int notpick;
    if(i>-1){
    notpick = f(wt, v, i-1, maxW, dp);
    if(wt[i]<=maxW) pick = v[i] + f(wt, v, i-1, maxW-wt[i], dp);
    }
    //     return maximum value
    return dp[i][maxW] = max(pick, notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    f(weight, value, n-1, maxWeight, dp);
    // returns max value from n-1 to 0 
    return dp[n-1][maxWeight];
}
