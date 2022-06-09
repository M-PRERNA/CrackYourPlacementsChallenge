int f(vector<int> &a, int i, int tar, vector<vector<int>> &dp){
    if(i==0){
        if(tar%a[0]==0) return tar/a[0];
        return 1e9;
    }
    if(dp[i][tar] != -1) return dp[i][tar];
        int pick = INT_MAX; int notpick;
        notpick = 0 + f(a, i-1, tar, dp);
        if(a[i]<=tar) pick = 1 + f(a, i, tar - a[i], dp);
    return dp[i][tar] = min(pick, notpick);
}
int minimumElements(vector<int> &num, int x)
{   vector<vector<int>> dp(num.size(), vector<int>(x+1, -1));
    int ans = f(num ,num.size()-1, x, dp); 
    if(ans>=1e9) return -1;
    return ans;
}
