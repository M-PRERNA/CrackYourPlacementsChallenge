// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. 
// Determine the maximum cost obtained by cutting the rod and selling its pieces.

int f(int i, int len, vector<int> &a, vector<vector<int>> &dp){
    if(len == 0) return 0;
    int rodlen = i+1;
    if(i == 0) return a[0] + f(i, len-rodlen, a, dp);

    if(dp[i][len] != -1) return dp[i][len];
    int pick = -1e9; int notpick;   
        if(len>=rodlen){
            pick = a[i] + f(i, len-rodlen, a, dp);
        }
        notpick = 0 + f(i-1, len, a, dp);
    return dp[i][len] = max(pick, notpick);
}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp (n, vector<int> (n+1, -1));
    return f(n-1, n, price, dp);
}
