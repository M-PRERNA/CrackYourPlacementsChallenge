#include <bits/stdc++.h>
using namespace std;


int print(vector<int> adj[])
{
  for (int i = 0; i < 12; i++)
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

int BFS(int i, vector<int> &visited, vector<int> adj[], vector<int> &colors)
{
    // visited[i] = 1;
    queue<int> Q;
    Q.push(i);
    visited[i] = 1;
    while (!Q.empty())
    {
        int ele = Q.front();
        cout << ele << " ";
        Q.pop();

        for (auto it : adj[ele])
        {   
            if(visited[it]){
                if(colors[it] == colors[ele]) return 0;
            }
            if (!visited[it])
            {
                Q.push(it);
                visited[it] = 1;
                if(colors[ele] == 1) colors[it] = 0;
                else colors[it] = 1;
            }
        }
    }

    return 1;
}

int BreadthFirstSearch(vector<int> adj[], int n, vector<int> &colors)
{
    vector<int> visited(n + 1, 0);
    int isBigraph = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {   
            colors[i] = 0;
            isBigraph *= BFS(i, visited, adj, colors);
        }
    }
    return isBigraph;
}

int main()
{
    int n = 11, m = 11;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        //     int u, v, wt;
        cin >> u >> v;

        adj[u].push_back(v); // adj[u].push_back({v, wt});
        adj[v].push_back(u); // adj[u].push_back({u, wt}); //comment this if directed graph
    }
    print(adj);

    vector<int> colors(n+1, -1);

    int val = BreadthFirstSearch(adj, n, colors);
    cout<<" it is a bipartite: "<<val;
    return 0;
}
