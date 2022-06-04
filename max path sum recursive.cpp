int f(int i, int j, vector<vector<int>> &m){
    
    if(i == m.size()-1) return m[i][j];
    int ldiag = -1e9; int rdiag = -1e9;
    int down  = m[i][j] + f(i+1, j,   m);
    if (j>0)             ldiag = m[i][j] + f(i+1, j-1, m);
    if (j<m[0].size()-1) rdiag = m[i][j] + f(i+1, j+1, m);
    
    return max(down, max(ldiag, rdiag));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(); //row 
    int m = matrix[0].size(); //columns
// we can move from any cell in first row to any cell on last row
    int maxi = -1e9;
    for (int col = 0; col<m; col++){
        int curr = f(0,col, matrix);
        if (curr>maxi) maxi = curr;
    }
    return maxi;
}
