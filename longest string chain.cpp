int checkIfPossible(string &a, string &b){
//     we know that a is greater in len than b
    int n = a.size(); 
    int m = b.size();
    if(n != m+1) return 0;
    int i=0, j=0;
    while (i<n){
        if(j<m && a[i] == b[j]){
            i++; j++;
        }
        else{
            i++;
        }
    }
    if (i==n && j==m) return 1;
    else return 0;
}

bool comp(string&s1, string&s2){
    return s1.size()<s2.size();
}
int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    sort(arr.begin(), arr.end(), comp); //sort based on size
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(checkIfPossible(arr[i], arr[j]) && 1 + dp[j]>dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        if(dp[i]>maxi) {
            maxi= dp[i];
        }
    }
    
    return maxi;
}
