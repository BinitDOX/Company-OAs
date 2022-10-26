#include<bits/stdc++.h>
using namespace std;

class DSU {
    public:
    vector<int> par;
    vector<int> siz;

    DSU(int n){
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.resize(n, 1);
    }

    int find(int u){
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    int unions(int u, int v){
        int lu = find(u);
        int lv = find(v);

        if(lu == lv)
            return -1;

        if(siz[lu] > siz[lv]){
            par[lu] = lv;
            siz[lv] += siz[lu];
        } else {
            par[lv] = lu;
            siz[lu] += siz[lv];
        }

        return max(siz[lu], siz[lv]);
    }

    int size(int u){
        return siz[find(u)];
    }
};

void solve(int v[], int u[], int n, int query[], int q){
    vector<int> vis(q, true);
    DSU dsu(n);

    for(int i=0; i<q; i++)
        vis[query[i]] = false;
    
    for(int i=0; i<q; i++)
        if(vis[i])
            dsu.unions(v[i], u[i]);

    vector<int> ans(q);
    for(int i=q-1; i>=0; i--){
        ans[i] = *max_element(dsu.siz.begin(), dsu.siz.end());
        int edge = query[i];
        dsu.unions(v[edge], u[edge]);
    }

    for(auto a : ans)
        cout<<a<<" ";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int v[n], u[n];
        for(int i=0; i<n-1; i++){
            cin>>v[i];
            v[i]--;
        }
        for(int i=0; i<n-1; i++){
            cin>>u[i];
            u[i]--;
        }

        int q;
        cin>>q;
        int query[q];
        for(int i=0; i<q; i++){
            cin>>query[i];
            query[i]--;
        }
        
        solve(v, u, n, query, q);
    }

    return 0; 
}