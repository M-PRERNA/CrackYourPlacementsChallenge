#include <bits/stdc++.h>
using namespace std;

bool DFS(int node, vector<int>&vis, vector<int>&dfsVis, vector<int> adj[]){
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it: adj[node]){
       if(!vis[it]) {
            if(DFS(it, vis, dfsVis, adj)){
                return true;
            }
       }
       else if(dfsVis[it]){
            return true;
       }
    }

    dfsVis[node] = 0;
    return false;
}

bool checkCycle(int n, vector<int> adj[]){
    
    vector<int> vis(n+1, 0);
    vector<int> dfsVis(n+1, 0);
    for(int i = 1; i<=n ; i++){
        if(!vis[i]){
            if(DFS(i, vis, dfsVis, adj)){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n = 9, m = 10;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    cout<<"There is a cycle: "<<checkCycle(n, adj);
    return 0;
}
