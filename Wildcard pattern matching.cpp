#include<bits/stdc++.h>
int f(int i, int j, string &s, string &t,  vector<vector<int>> &dp) {
//     base case
    if (i<0 && j<0) return true;
    if (i<0 && j>=0) return false; //string remaing pattern over
    if (j<0 && i>=0) // pattern remaining string over'
    {   for(int ii=0; ii<=i; ii++){ 
            if (s[ii] != '*') 
                return false; 
            } //if by chance no * then false
        return true; //all *s
    }
//     do something
    if (s[i] == '?' || s[i] == t[j]) return dp[i][j] = f(i-1, j-1, s, t, dp);
    
    if (s[i] == '*') {return dp[i][j] = f(i-1, j, s, t, dp) | f(i, j-1, s, t, dp);}
//     return true if match else retur false
    return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return f(n-1, m-1, pattern, text, dp);
}
