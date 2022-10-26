bool isValidSudoku(vector<vector<char>>& mat) {
    int n = mat.size();

    vector<vector<bool>> rmap(n, vector<bool>(n));
    vector<vector<bool>> cmap(n, vector<bool>(n));
    vector<vector<bool>> smap(n, vector<bool>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] != '.'){
                if(rmap[mat[i][j]-'0'-1][i] == false)
                    rmap[mat[i][j]-'0'-1][i] = true;
                else
                    return false;
                if(cmap[mat[i][j]-'0'-1][j] == false)
                    cmap[mat[i][j]-'0'-1][j] = true;
                else
                    return false;
                if(smap[mat[i][j]-'0'-1][(i/3)*3+j/3] == false)
                    smap[mat[i][j]-'0'-1][(i/3)*3+j/3] = true;
                else
                    return false;                    
            }
        }
    }
    return true;
}