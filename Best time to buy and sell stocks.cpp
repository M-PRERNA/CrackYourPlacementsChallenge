#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int mincost = prices[0];
    int maxprofit = 0;
    for (int i = 1; i<n; i++){
        int cost = prices[i] - mincost;
        maxprofit = max(cost, maxprofit); // update the max profit
        mincost   = min(mincost, prices[i]); // update the mincost 
    }
    return maxprofit;
}
