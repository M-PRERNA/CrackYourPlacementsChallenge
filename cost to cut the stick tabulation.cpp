#include<bits/stdc++.h>
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
//     tabulation
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
    for(int i = c; i>=1; i--){
        for (int j = 1; j<=c; j++){
            if(i>j) continue;
            int mini = INT_MAX;
            for(int ind = i; ind<=j; ind++){
            int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
            mini = min(cost, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}
