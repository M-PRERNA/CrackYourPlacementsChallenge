#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >>n>>m;
//   m is the number of edges --- n is the number of nodes
//  a----b----c
//  |          \
//  f-----g-----h
//  |           |
//  d----e------k   here m = 10 and n=9
//   the loop will look like: 
// [m:  u-----v]
//  0:  a ----b
//  1:  b-----c
//  2:  c-----h
//  3:  a------f
//  4:  f------g
//  5:  g------h
//  6:  h------k
//  7:  e------k
//  8:  f------d
//  9:  d-------e
  
//   adjacency list:
//   [a]:(b, f)
//   [b]:(a, c)
//   [c]:(b, h)
//   [d]:(f, e)
//   [e]:(k, d)
//   [f]:(g, d)
//   [g]:(f, h)
//   [h]:(g, k)
//   [k]:(e, h)
  vector<int> adj[n+1]; //array of adjacency lists
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
