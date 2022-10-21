bool dfs(vector<int> adj[], int v, int p, vector<int> &vis, vector<int> &ans, int &mark){
    vis[v] = true;

    for(auto u : adj[v]){
        if(!vis[u]){
            if(dfs(adj, u, v, vis, ans, mark)){
                if(mark != -1)
                    ans.push_back(v);
                if(mark == v)
                    mark = -1;
                return true;
            }
        } else if(u != p){
            mark = u;
            if(mark == v)
                mark = -1;
            ans.push_back(v);
            return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[]) {
    vector<int> vis(n);
    vector<int> ans;
    int mark = -1;

    for(int i=0; i<n; i++)
        if(!vis[i])
         if(dfs(adj, i, -1, vis, ans, mark)){
            for(auto x : ans)
                cout<<x<<" ";
            return true;
         }

    return false;
}