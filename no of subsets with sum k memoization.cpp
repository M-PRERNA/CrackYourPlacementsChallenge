int f(int i, int t, vector<int> &a, vector<vector<int>> &dp){
    if(t == 0) return 1;
    if(i == 0) return a[i] == t;
    
    if(dp[i][t] != -1) return dp[i][t];
    
    int notPick = f(i-1, t, a, dp); 
    int pick = 0;
    if(a[i]<=t) pick = f(i-1, t-a[i], a, dp);
    
    return dp[i][t] = pick+notPick;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    return f(num.size()-1, tar, num, dp);
}
