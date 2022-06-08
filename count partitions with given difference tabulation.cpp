int mod = (int) 1e9  + 7;
int f(vector<int> &arr, int k, int i){
    if(i==0){
        if(k==0 && arr[0] == 0) return 2;
        if(k==0 || k == arr[0]) return 1;
        return 0;
        }
    
    int pick=0; int notpick; 
    if(i>-1){
    if(arr[i]<=k) 
        pick = f(arr, k-arr[i], i-1);
    notpick = f(arr, k, i-1);
    }
    return pick+notpick;
}


int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, 0));
    
    if(num[0] == 0) dp[0][0] = 2; // 0 can be either picked or not picked will not cause any change
    else dp[0][0] = 1; // else only one way is there that is not take
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1; // we pick the value
    
    for(int ind = 1; ind< num.size(); ind++){
        for (int t=0; t<tar+1; t++){
            
            int notPick = dp[ind-1][t];
            int pick = 0;
            if(num[ind]<=t) pick = dp[ind-1][t - num[ind]];
            
            dp[ind][t] = (pick+notPick)%mod;
        }
    }
    return dp[num.size()-1][tar];   
}


int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int s=0;
    for(auto &it: arr) s+=it;
    if(s-d < 0 || (s-d)%2 !=0) return 0;
    int k = (s-d)/2;
    return findWays(arr, k);
}
