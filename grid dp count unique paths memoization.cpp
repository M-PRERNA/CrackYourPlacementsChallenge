#include <bits/stdc++.h> 

int f(int i, int j, vector<vector<int>> &dp){
    if (i==0 && j==0){
        return dp[0][0] = 1;
    }
    if (i <0 || j<0){
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
//     since we are starting from rightmost corner to wards leftmost corner
    int left = f(i, j-1, dp);
    int up = f(i-1, j, dp);
    
    return dp[i][j] = left+up;
}
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m, vector<int>(n,-1));
    f(m-1, n-1, dp);
    return dp[m-1][n-1];
}
