int f(int ind, int buy, int cap, vector<int>& p, vector<vector<vector<int>>> dp){
    if(cap == 0) return 0;
    if(ind == p.size()) return 0;
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    if (buy){
        return dp[ind][buy][cap] = max(-p[ind] + f(ind+1, 0, cap, p, dp), 0 + f(ind+1, 1, cap, p, dp));
    }
    else{
        return dp[ind][buy][cap] = max(p[ind] + f(ind+1, 1, cap-1, p, dp), 0 + f(ind+1, 0, cap, p, dp));
    }
}

int maxProfit(vector<int>& prices, int n)
{   //memoization gives a TLE because of the auxiliary stack space
//     vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));
    
//     tabulation
    for(int i = n-1; i>=0; i--){
        for(int j = 0; j<2; j++){
            for(int k = 1; k<3; k++){
                if (j){
                    curr[j][k] = max(-prices[i] + next[0][k], 0 + next[1][k]);
                }
                else{
                    curr[j][k] = max(prices[i] + next[1][k-1], 0 + next[0][k]);
                }
            }
        }
        next = curr;
    }   
    return curr[1][2];
}
