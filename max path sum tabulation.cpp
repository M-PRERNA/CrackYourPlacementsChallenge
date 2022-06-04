int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(); //row 
    int m = matrix[0].size();//columns
    vector<vector<int>> dp (n, vector<int> (m, 0));
    for(int i = 0 ; i<m; i++){
        dp[n-1][i]= matrix[n-1][i];    
    }
// we can move from any cell in first row to any cell on last row
   
    for(int row = n-2; row>=0; row--){
        for(int col = m-1; col>=0; col--){
            int left = -1e9; int right = -1e9;
            if (col>0) left  = matrix[row][col] + dp[row+1][col-1];
            if (col<m-1) right = matrix[row][col] + dp[row+1][col+1];
            int down  = matrix[row][col] + dp[row+1][col];
            
            dp[row][col] = max(down, max(left, right));
        }
    }
    int maxi = -1e9;
    for (int col = 0; col<m; col++){
        int curr = dp[0][col];
        if (curr>maxi) maxi = curr;
    }
    return maxi;
}
