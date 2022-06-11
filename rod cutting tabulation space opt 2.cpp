int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1, 0);

//     space optimization : space complexity : O(n) single array instead of O(n^2);
    for(int i = 1; i< n+1; i++){
        prev[i] = price[0] + prev[i-1];
}
    
    for(int ind = 1; ind< n; ind++){
        for(int rodlen = 0; rodlen< n+1; rodlen++){
            int pick = -1e9; int notpick;   
            if(rodlen>ind){
                pick = price[ind] + prev[rodlen-ind-1];
            }
            notpick = 0 + prev[rodlen];
            prev[rodlen] = max(pick, notpick);
            }
    }
    return prev[n];
}
