#include<bits/stdc++.h>
int lcs(string s, string t)
{
    vector<int> curr (t.size(), 0);
    vector<int> prev (t.size(), 0);
    for(int j = 0; j<t.size(); j++){
        if(s[0] == t[j]) prev[j] = 1;
    }
    
    for(int i = 1; i<s.size(); i++){
        for(int j = 1; j<t.size(); j++){
           if(s[i] == t[j]) curr[j] = 1 + prev[j-1];
            
           else curr[j] = 0 + max(prev[j], curr[j-1]);
        }
        prev = curr;
    }

    return prev[t.size()-1];
}
