#include<bits/stdc++.h>
using namespace std;

 struct PQNode {
    int r;
    int c;
    int w;
    
    PQNode (int i, int j, int k){
        r = i;
        c = j;
        w = k;
    }
    
    bool operator<(PQNode const &pqn) const {
        return w > pqn.w;
    }
};

int minimumEffortPath(vector<vector<int>>& mat, int sr, int sc, int er, int ec) {
    int n = mat.size();
    int m = mat[0].size();
    int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    priority_queue<PQNode> pq;
    int ans = 0;
    pq.push(PQNode(sr, sc, 0));
    
    while(!pq.empty()){
        PQNode node = pq.top();
        pq.pop();
        mat[node.r][node.c] = -mat[node.r][node.c];
        
        ans = max(ans, node.w);
        if(node.r == er && node.c == ec)
            return ans;
        
        for(int d=0; d<4; d++){
            int r = node.r + dir[d][0];
            int c = node.c + dir[d][1];
            if(r>=0 && c>=0 && r<n && c<m && mat[r][c] > 0){
                int effort = abs(-mat[node.r][node.c] - mat[r][c]);
                pq.push(PQNode(r, c, effort));
            }
        }
    }
    return -1;
}
    
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        cout<<minimumEffortPath(mat, 0, 0, n-1, m-1)<<endl;
    }
    return 0;
}