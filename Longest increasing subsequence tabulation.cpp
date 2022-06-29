#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{ 
//     tabulation space optimised (gives TLE)
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    vector<int> next(n+1, 0), curr(n+1, 0);
//     return f(0, -1, arr, dp, n);
    for(int ind = n-1; ind>=0; ind--){
        for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--){
            int len = 0 + next[prev_ind+1];
            if(prev_ind == -1 || arr[ind]>arr[prev_ind]){
                len = max(len, 1+next[ind+1]);
            }
            curr[prev_ind+1] = len;
        }
        next = curr;
    }
    return curr[-1+1];
}
