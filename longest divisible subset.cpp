#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    // longest increasing subsquence with the hash with a mi nor change
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastind =0;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int prev=0; prev<i; prev++){
            if(arr[i]%arr[prev] == 0 && 1 + dp[prev]>dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i]>maxi) {
            maxi= dp[i];
            lastind = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastind]);

    while(hash[lastind]!=lastind){
        lastind = hash[lastind];
        temp.push_back(arr[lastind]);
        
    }
    reverse(temp.begin(), temp.end());
    
    return temp;
}
