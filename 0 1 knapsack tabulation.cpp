int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    if(n==1 && maxWeight>=weight[0]) return value[0];
    
    for (int item = weight[0]; item<maxWeight+1; item++){ //this part important
        dp[0][item] = value[0];
    }
    for (int i = 1; i<n; i++){
        for(int j = 0; j<maxWeight+1; j++){
            
            int pick = 0; int notpick;
            notpick = dp[i-1][j];
            if(weight[i]<=j) pick = value[i] + dp[i-1][j-weight[i]];
            dp[i][j] = max(pick, notpick);
        }
    }
    return dp[n-1][maxWeight];
}
