int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp (n, vector<int> (n+1, 0));
    dp[0][0] = 0;
    for(int i = 1; i< n+1; i++){
        dp[0][i] = price[0] + dp[0][i-1];
}
    for(int ind = 1; ind< n; ind++){
        for(int rodlen = 0; rodlen< n+1; rodlen++){
            int pick = -1e9; int notpick;   
            if(rodlen>ind){
                pick = price[ind] + dp[ind][rodlen-ind-1];
            }
            notpick = 0 + dp[ind-1][rodlen];
            dp[ind][rodlen] = max(pick, notpick);
            }
    }
    return dp[n-1][n];
}
