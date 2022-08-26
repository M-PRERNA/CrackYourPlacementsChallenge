//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include<algorithm>
class Solution{
public:
    int isSuperSimilar(int n, int m, vector<vector<int>>& mat, int x)
    {
       vector<vector<int>> rmat = mat;
       
       for(int i = 0; i<n ;i++){
           if (i%2 == 0){
            //   rotate left
            vector<int> thisRow = rmat[i];
                rotate(thisRow.begin(), thisRow.begin()+x, thisRow.end());
                rmat[i] = thisRow;
           }
           else{
            //   rotate right
            vector<int> thisRow = rmat[i];
            // cout<<"else part";
            rotate(thisRow.begin(), thisRow.begin()+m-x, thisRow.end());
            rmat[i] = thisRow;
           }
       }
       
       int flag = 1;
       
       for(int row = 0; row<n; row++){
           for(int col = 0; col<m; col++){
               if(mat[row][col] != rmat[row][col]) flag = 0;
           }
       }
       
       return flag;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        int x;
        cin >> x;
        
        Solution ob;
        cout<<ob.isSuperSimilar(n,m,mat,x)<<endl;
    }
    return 0;
}
// } Driver Code Ends
