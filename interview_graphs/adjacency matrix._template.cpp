#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int n, m;
  int adj[n+1][n+1]; //for 1 based index of the vecrtices
  
  for(int i=1; i<=n; i++){
    int u, v;
    cin>> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  
 return 0;
  
}
