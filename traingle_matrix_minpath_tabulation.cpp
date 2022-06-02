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
    vector<vector<int>> dp(n , vector<int>(n, 0));
    // tabulation is bottom up approach
    for (int i=0; i<n; i++){
        dp[n-1][i] = triangle[n-1][i]; 
    }
    for(int i=n-2; i>=0; i-- ){
        for(int j = n-2; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int dg = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, dg);
        }
    }
    return dp[0][0];
}
