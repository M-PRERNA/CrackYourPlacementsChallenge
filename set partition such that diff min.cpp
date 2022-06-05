int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totSum = 0;
    for(int i=0; i<n; i++) totSum+=arr[i];
    int k = totSum;
	vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int ind = 0; ind<n; ind++){
        dp[ind][0] = true;
    }
    dp[0][arr[0]] = true;
    
    for(int i = 1; i<n; i++){
        for (int target = 1; target <k+1; target++){
            bool notpick = dp[i-1][target];
            bool pick = false;
            if(arr[i]<=target) pick = dp[i-1][target-arr[i]];
   
            dp[i][target] = pick| notpick;
        }
    }
    int mini = 1e9;
    for(int j =0; j<k+1; j++){
        if(dp[n-1][j] == true)
        {
            int s1 = j;
            int s2 = totSum-j;
            
            mini = min (mini, abs(s1-s2));
        }
    }
    
    return mini;
    
}
