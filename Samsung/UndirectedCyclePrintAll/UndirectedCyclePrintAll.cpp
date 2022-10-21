unordered_map<int, vector<int>> dfs(vector<int> adj[], int v, int p, vector<bool> &vis, vector<vector<int>> &cycles){
    vis[v] = true;

    unordered_map<int, vector<int>> um;
    for(auto u : adj[v]){
        if(!vis[u]){
            auto rm = dfs(adj, u, v, vis, cycles);
            for(auto &x : rm){
                x.second.push_back(v);
                if(v == x.first)
                    cycles.push_back(x.second);
                um[x.first] = x.second;
            }
        } else if(u != p){
            um[u].push_back(v);
        }
    }
    return um;
}

bool isCycle(int n, vector<int> adj[]) {
    vector<bool> vis(n);
    vector<vector<int>> cycles;

    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(adj, i, -1, vis, cycles);

    for(auto cycle : cycles){
        for(auto c : cycle)
            cout<<c<<" ";
        cout<<endl;
    }

    return false;
}