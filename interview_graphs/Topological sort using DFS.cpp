#include<bits/stdc++.h>
using namespace std;

int DFS(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            DFS(it, vis, adj, st);
        }
    }

    st.push(node);
    return 0;
}
int main(){
    int n = 5, m = 6;
    vector<int> adj[n+1];

    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);

    vector<int> vis(n+1, 0);
    stack<int> st;

    for(int i = 0; i<=n; i++){
        if(!vis[i]){
            DFS(i, vis, adj, st);
        }
    }

    while(!st.empty()){
        int val = st.top();
        st.pop();
        cout<<val<<" ";
    }

    return 0;
}
