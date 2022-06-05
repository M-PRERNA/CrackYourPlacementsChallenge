
bool subsetSumToK(int n, int k, vector<int> &arr) {
//     for tabulation we do not need any integer
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int ind = 0; ind<n; ind++){
        dp[ind][0] = true;
    }
    dp[0][arr[0]] = true;
    
    for(int i = 1; i<n; i++){
        for (int target = 1; target <k+1; target++){
            bool notpick = dp[i-1][target];
            bool pick = false;
            if(arr[i]<=target) pick = dp[i-1][target-arr[i]];
   
            dp[i][target] = pick| notpick;
        }
    }
    
    return dp[n-1][k];

}
