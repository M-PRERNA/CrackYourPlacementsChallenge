#include<bits/stdc++.h>
using namespace std;

int checkCycle(int node, int prev, vector<int> &visited, vector<int> adj[]){

    visited[node] = 1;
    for(int it: adj[node]){
        if(visited[it] && it != prev){
            return 1;
        }
        else if(!visited[it]){
            return checkCycle(it, node, visited, adj);
        }
    }

    return 0;
}

int main(){
    int n = 7, m = 6;
    vector<int> adj[n+1];

    adj[1].push_back(2); 
    adj[2].push_back(1);

    adj[2].push_back(4); 
    adj[4].push_back(2);

    adj[4].push_back(6); 
    adj[6].push_back(4);

    adj[6].push_back(7); 
    adj[7].push_back(6);

    adj[7].push_back(2); 
    adj[2].push_back(7);

    adj[3].push_back(5); 
    adj[5].push_back(3);

    vector<int> visited(n+1, 0);
    int check = 0;

    for (int i = 1; i<= n; i++){
        if(!visited[i]){
            if (checkCycle(i, -1, visited, adj)) {check = 1; break;}
        }
    }
    cout<<check;
    return 0;
}
