#include <bits/stdc++.h>
using namespace std;

int print(vector<int> adj[])
{
  for (int i = 0; i < 8; i++)
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

int DFS(int i, vector<int> &visited, vector<int> adj[])
{
  visited[i] = 1;
  cout << i << " ";
  for (int it : adj[i])
  {
    if (!visited[it])
    {

      DFS(it, visited, adj);
    }
  }
  return 0;
}

int DepthFirstSearch(vector<int> adj[], int n)
{
  vector<int> visited(n + 1, 0);
  vector<int> storeDFS;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      DFS(i, visited, adj);
    }
  }
  return 0;
}

int main()
{
  int n = 7, m = 6;
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
  DepthFirstSearch(adj, n);
  return 0;
}
