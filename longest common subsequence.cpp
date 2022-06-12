#include<bits/stdc++.h>
int lcs(string &s, string &t)
{
    vector<int> curr (t.size()+1, 0);
    vector<int> prev (t.size()+1, 0);
// cell shifting required
    int ans = 0;
    for(int i = 1; i<=s.size(); i++){
        for(int j = 1; j<=t.size(); j++){
           if(s[i-1] == t[j-1]) {
               curr[j] = 1 + prev[j-1];
               ans = max(ans, curr[j]);
        }  
           else curr[j] = 0;
        }
        prev = curr;
    }

    return ans;
}
