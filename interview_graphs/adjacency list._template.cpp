#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >>n>>m;
  vector<int> adj[n+1];
//vector<pair<int, int>> adj[n+1];
  for(int i = 0; i<m; i++){
    int u, v;
//     int u, v, wt;
    cin >>u>>v;
//  cin>>u>>v>>wt;
//  for undirected graph 
    adj[u].push_back(v); //adj[u].push_back({v, wt});
    adj[v].push_back(u); //adj[u].push_back({u, wt}); //comment this if directed graph 
  }
  return 0;
}
