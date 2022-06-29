int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
//     tabulation: bottom-up
//     1. copy the base case
//     2. write down the changing states
//     i: n-1  to  0
//     j: i+1  to n-1 ((j can never go to the left of i))
//     3. copy the recurrence
//     vector<vector<int>> dp(n, vector<int> (n, -1));
    int dp[n][n];
    for(int i =0; i<n; i++) dp[i][i] = 0;
    for(int i = n-1; i>=1; i--){
        for(int j = i+1; j<=n-1; j++){
            
            int mini = 1e9;
            for(int k = i; k<j; k++){
            int step = arr[i-1]*arr[j]*arr[k] + dp[i][k] + dp[k+1][j];
            mini = min(mini, step);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}
