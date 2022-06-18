#include<bits/stdc++.h>
long f(int ind, int buy, long *p, int n){
    if (ind == n) return 0;
    long profit = 0;
    if(buy){
        profit = max(-p[ind] + f(ind+1, 0, p, n), 
                          0 + f( ind+1, 1, p, n));
    }
    else{
        profit = max(p[ind] + f(ind+1, 1, p, n), 
                          0 + f( ind+1, 0, p, n));
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    return f(0, 1, values, n);
    
}
