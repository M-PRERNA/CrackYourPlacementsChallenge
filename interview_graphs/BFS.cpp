#include <bits/stdc++.h>
using namespace std;

int BFS(int i, vector<int> &visited, vector<int> adj[])
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
            if (!visited[it])
            {
                Q.push(it);
                visited[it] = 1; 
            }
        }
    }
    return 0;
}

int BreadthFirstSearch(vector<int> adj[], int n)
{
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            BFS(i, visited, adj);
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
    BreadthFirstSearch(adj, n);
    return 0;
}
