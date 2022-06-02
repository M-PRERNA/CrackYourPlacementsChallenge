int f( vector<vector<int>> & t, int i, int j, vector<vector<int>> & dp){
//    base case
    if(i==t.size()-1) return t[i][j];
//    actual logic
    if (dp[i][j] !=-1) return dp[i][j];
    int down = t[i][j] + f(t, i+1,j, dp);
    int dg   = t[i][j] + f(t, i+1, j+1, dp);
    return dp[i][j] = min(down, dg);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n , vector<int>(n, -1));
    return f(triangle, 0,0 ,dp);
}
