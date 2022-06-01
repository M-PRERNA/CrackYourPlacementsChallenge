#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m, vector<int>(n,0));
    dp[0][0] = 1;
    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) {dp[0][0] = 1; continue;};
            int top=0; int left =0;
            if(i>0) top = dp[i-1][j];
            if(j>0) left = dp[i][j-1];
            
            dp[i][j] = left+top;
        }
    }
    return dp[m-1][n-1];
}
