//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> result;
        vector<string> stringList;
        
        for (int index = 0; index<n; index++){
            stringList.push_back(contact[index]);
        }
        sort(stringList.begin(), stringList.end());
        auto it = std::unique(stringList.begin(), stringList.end());
        stringList.resize(std::distance(stringList.begin(), it));
        
        for (int i = 0; i < s.length(); i++){
            vector<string> queryList;
            for (int Contact = 0; Contact < stringList.size(); Contact++){
                int flag = 1;
                for(int j = 0; j<=i ; j++){
                    
                    if(stringList[Contact][j] != s[j]) flag = 0;
                   
                }
                if(flag == 1) queryList.push_back(stringList[Contact]);
            }
            if (queryList.size()>0) {
                
                sort(queryList.begin(), queryList.end());
                
                result.push_back(queryList);}
            else {
                result.push_back({"0"});
                
            }
        }
        
    return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
