int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    for(int k = i; k<j; k++){
        int step = arr[i-1]*arr[j]*arr[k] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        mini = min(mini, step);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return f(1, n-1, arr, dp);
}
