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

void solve(int v[], int u[], int n, int m){
    DSU dsu(n);
    int maxs = 1;

    for(int i=0; i<m; i++)
        maxs = max(maxs, dsu.unions(v[i], u[i]));
    
    cout<<maxs<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        int v[m], u[m];
        for(int i=0; i<m; i++){
            cin>>v[i];
            v[i]--;
        }
        for(int i=0; i<m; i++){
            cin>>u[i];
            u[i]--;
        }
        
        solve(v, u, n, m);
    }

    return 0; 
}