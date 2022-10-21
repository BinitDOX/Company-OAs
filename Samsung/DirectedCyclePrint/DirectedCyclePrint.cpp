bool dfs(vector<int> adj[], int v, vector<int> &vis, vector<int> &ans, int &mark){
    vis[v] = 1;

    for(int u : adj[v]){
        if(!vis[u]){
            if(dfs(adj, u, vis, ans, mark)){
                if(mark != -1)
                    ans.push_back(v);
                if(mark == v)
                    mark = -1;
                return true;
            }
        } else if(vis[u] == 1){
            mark = u;
            if(mark == v)
                mark = -1;
            ans.push_back(v);
            return true;
        }
    }

    vis[v] = 2;
    return false;
}

bool isCyclic(int n, vector<int> adj[]) {
    vector<int> vis(n); // 0: unvis, 1:localvis, 2:globalvis
    vector<int> ans;
    int mark = -1;

    for(int i=0; i<n; i++){
        if(dfs(adj, i, vis, ans, mark)){
            for(auto x : ans)
                cout<<x<<" ";
            return true;
        }
    }

    return false;
}