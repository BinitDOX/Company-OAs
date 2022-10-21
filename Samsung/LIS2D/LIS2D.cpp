int dfs(vector<vector<int>>& mat, int sr, int sc, int er, int ec, int dir[][2], vector<vector<int>> &memo){
    int len = 0;
    
    if(memo[sr][sc] != -1)
        return memo[sr][sc];
    
    for(int d=0; d<4; d++){
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];
        if(r>=0 && c>=0 && r<=er && c<=ec && mat[r][c] > mat[sr][sc]){
            len = max(len, dfs(mat, r, c, er, ec, dir, memo));
        }
    }
    
    return memo[sr][sc] = len + 1;
}

int longestIncreasingPath(vector<vector<int>>& mat, int n, int m) {
    int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> memo(n, vector<int>(m, -1));
    
    int len = 1;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            len = max(len, dfs(mat, i, j, n-1, m-1, dir, memo));
            
    return len;
}