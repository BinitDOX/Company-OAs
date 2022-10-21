bool dfs(vector<int> adj[], int v, vector<int> &color){
    for(int u : adj[v])
        if(color[u] == -1){
            color[u] = !color[v];
            if(!dfs(adj, u, color))
                return false;
        } else if(color[u] == color[v]){
            return false;
        }
    return true;
}

bool isBipartite(int n, vector<int>adj[]){
    vector<int> color(n, -1); // -1 = not visited

    for(int i=0; i<n; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!dfs(adj, i, color))
                return false;
        }
    }

    vector<int> set1, set2;
    for(int i=0; i<n; i++){
        if(color[i] > 0)
            set1.push_back(i);
        else
            set2.push_back(i);
    }

    for(int i=0; i<set1.size(); i++)
        cout<<set1[i]<<" ";
    cout<<endl;

    for(int i=0; i<set2.size(); i++)
        cout<<set2[i]<<" ";
    cout<<endl;

    return true;
}