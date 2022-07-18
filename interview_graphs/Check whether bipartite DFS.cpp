#include <bits/stdc++.h>
using namespace std;

int print(vector<int> adj[])
{
  for (int i = 0; i < 9; i++)
  {
    cout << "\"" << i << "\" ";
    for (auto it : adj[i])
    {
      cout << it << " ";
    }
    cout << "\n";
  }
  return 0;
}

int DFS(int i, vector<int> &visited, vector<int> adj[], vector<int> &colors)
{
  visited[i] = 1;
  cout << i << " ";
  for (int it : adj[i])
  { 
    if( visited[it]){
      if(colors[it] == colors[i]) return 0;
    }
    if (!visited[it])  //if not visited means not colored
    { 
      colors[it] = 1 - colors[i];
      DFS(it, visited, adj, colors);
    }
  }
  return 1;
}

int DepthFirstSearch(vector<int> adj[], int n)
{
  vector<int> visited(n + 1, 0);
  vector<int> storeDFS;
  vector<int> colors(n+1, -1);
  int check = 1;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    { 
      colors[i] = 0;
      check *= DFS(i, visited, adj, colors);
    }
  }
  return check;
}

int main()
{
  int n = 8, m = 8;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    //     int u, v, wt;
    cin >> u >> v;

    adj[u].push_back(v); // adj[u].push_back({v, wt});
    adj[v].push_back(u); // adj[u].push_back({u, wt}); //comment this if directed graph
  }
  // print(adj);
  cout<<"\nIs it bipartite:  "<<DepthFirstSearch(adj, n);
  return 0;
}
