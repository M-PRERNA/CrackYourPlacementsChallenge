// memoization
bool f(vector<int> &arr, int k, int i, vector<vector<int>> &dp){
    if(k==0)  return true;
    if (i==0) return arr[i]==k;
    
    if(dp[i][k] != -1) return dp[i][k];
    
//     int pick=0; int notpick = 0;
    bool notpick = f(arr, k, i-1, dp);
    bool pick = false;
    if(arr[i]<=k) pick = f(arr, k-arr[i], i-1, dp);
   
    return dp[i][k] = pick| notpick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(arr, k, n-1, dp); 

}
