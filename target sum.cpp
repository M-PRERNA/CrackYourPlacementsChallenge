// You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build an expression out of an array by adding one of the symbols 
// '+' and '-' before each integer in an array, and then by concatenating all the integers, you want to achieve a target. 
//  You have to return the number of ways the target can be achieved.

int mod = (int) 1e9  + 7;
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, 0));
    if(num[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;
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

int targetSum(int n, int target, vector<int>& arr) {
    int d = target;
    int s=0;
    for(auto &it: arr) s+=it;
    if(s-d < 0 || (s-d)%2 !=0) return 0;
    int k = (s-d)/2;
    return findWays(arr, k);
}
