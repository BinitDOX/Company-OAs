#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int p, int v, vector<bool> &vis){
    if(vis[v]){
        vis[p] = true;
        return;
    }

    for(int u : adj[v])
        dfs(adj, v, u, vis);
}

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> adj[n+1];
    for(int i=1; i<n+1; i++){
        int v;
        cin>>v;
        adj[i].push_back(v);
    }

    vector<bool> vis(n+1);
    vis[0] = true;

    vector<int> projects(k);
    for(int i=0; i<k; i++)
        cin>>projects[i];

    for(int i=0; i<k; i++)
        dfs(adj, projects[i], projects[i], vis);
    
    for(int i=1; i<=n; i++)
        if(!vis[i])
            cout<<i<<" ";

    return 0; 
}