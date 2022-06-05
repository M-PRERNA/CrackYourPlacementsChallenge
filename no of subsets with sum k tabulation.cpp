
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, 0));
    
    for(int i=0; i< num.size(); i++){
        dp[i][0] = 1;
    }
    
    if(num[0]<=tar) dp[0][num[0]] = 1;
    
    for(int ind = 1; ind< num.size(); ind++){
        for (int t=0; t<tar+1; t++){
            
            int notPick = dp[ind-1][t];
            int pick = 0;
            if(num[ind]<=t) pick = dp[ind-1][t - num[ind]];
            
            dp[ind][t] = pick+notPick;
        }
    }
    return dp[num.size()-1][tar];   
}
