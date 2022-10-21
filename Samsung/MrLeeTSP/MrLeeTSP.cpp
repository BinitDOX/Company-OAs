#include<bits/stdc++.h>
using namespace std;


int tsp(vector<vector<int>> &mat, int s, int v, int vis, int n){
    if(vis == (1<<n) - 1)
        return mat[v][s] == 0 ? 1e7 : mat[v][s];

    int cost = 1e7;
    for(int i=0; i<n; i++){
        if(mat[v][i] && (vis & (1<<i)) == 0) {
            vis ^= 1<<i;
            cost = min(cost, tsp(mat, s, i, vis, n)+mat[v][i]);
            vis ^= 1<<i;
        }
    }
    return cost;
}

int solve(vector<vector<int>> &mat, int n){
    int vis = 1;
    int v = 0;

    return tsp(mat, v, v, vis, n);
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<vector<int>> mat(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];

        cout<<solve(mat, n)<<endl;

    }
    return 0;
}

