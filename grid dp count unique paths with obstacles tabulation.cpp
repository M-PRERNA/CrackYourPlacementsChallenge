int mod = (int) (1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
int dp[n][m];
//     dp[0][0] = 1;
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == -1) dp[i][j] = 0;
            else if(i==0 && j==0) dp[0][0] = 1; 
            else{
            int top=0; int left =0;
            if(i>0) top = dp[i-1][j];
            if(j>0) left = dp[i][j-1];
            
            dp[i][j] = (left+top)%mod;}
        }
    }
    return dp[n-1][m-1];
}
