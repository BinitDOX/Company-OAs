#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, unordered_map<int, int>> &adj, int v, unordered_set<int> &vis, vector<int> &ka, int k){
    vis.insert(v);

    if(k == 0){
        ka.push_back(v);
        return;
    }

    for(auto u : adj)
        if(adj[v][u.first] && vis.find(u.first) == vis.end())
            dfs(adj, u.first, vis, ka, k-1);
}

void solve(unordered_map<int, unordered_map<int, int>> &adj, int n, int k){
    unordered_set<string> ans;

    for(auto &x : adj){
        unordered_set<int> us;
        vector<int> ret;
        dfs(adj, x.first, us, ret, k);
        for(int r : ret){
            // cout<<x.first<<" "<<r<<endl;
            int s = x.first;
            if(s < r)
                swap(s, r);
            ans.insert(to_string(r)+"#"+to_string(s));
        }
    }

    cout<<ans.size()<<endl;
}

int main(){
    int n, k;
    cin>>n>>k;

    unordered_map<int, unordered_map<int, int>> um;
    for(int i=0; i<n; i++){
        int u, v;
        cin>>v>>u;

        um[v][u] = 1;
        um[u][v] = 1;
    }

    solve(um, n, k);

    return 0; 
}