
int  f(int i, int j, string &s, string &t, vector<vector<int>> &dp){

    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j] != -1 ) return dp[i][j];

    int ins = 0, del=0, rep=0;
    if(s[i] == t[j]) return 0+f(i-1, j-1, s, t, dp);

    ins = 1 + f(i, j-1, s, t, dp);
    del = 1 + f(i-1, j, s, t, dp);
    rep = 1 + f(i-1, j-1, s, t, dp);
 
    return dp[i][j] = min(ins, min(rep, del));
}
int editDistance(string str1, string str2)
{

    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp (n, vector<int> (m, -1));
    return f(n-1, m-1, str1, str2, dp);

}
