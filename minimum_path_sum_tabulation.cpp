#include<bits/stdc++.h>
// int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//     if (i==0 && j==0)  return grid[i][j];
//     if (i<0 || j<0) return 1e9;
//     if(dp[i][j] != -1) return dp[i][j];
//     int up =0; int left=0;
//     up = grid[i][j] + f(i-1, j, grid, dp);
//     left = grid[i][j] +f(i, j-1, grid, dp);
    
//     return dp[i][j] = min(up, left);
    
// }
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    dp[0][0] = grid[0][0];
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if (i==0 && j==0) dp[i][j] = grid[i][j];
            else{ 
            int right = 1e9; int down =1e9;
            if (j>0) right = grid[i][j] + dp[i][j-1];
            if (i>0) down = grid[i][j] + dp[i-1][j];
            
            dp[i][j] = min(right, down);}
        }
    }
    
//     f(m-1, n-1, grid, dp);
    return dp[m-1][n-1];
}
