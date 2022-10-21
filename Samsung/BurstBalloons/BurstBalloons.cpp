int maxCoins(vector<int>& arr) {
    int n = arr.size();
    int dp[n][n];
    
    for(int g=0; g<n; g++){
        for(int j=g, i=0; j<n; j++, i++){
            dp[i][j] = 0;
            for(int k=i; k<=j; k++){
                int l = k == i ? 0 : dp[i][k-1];
                int r = k == j ? 0 : dp[k+1][j];
                int v = (i > 0 ? arr[i-1] : 1) * arr[k] * (j < n-1 ? arr[j+1] : 1);
                dp[i][j] = max(dp[i][j], l+v+r);
            }
        }
    }
    return dp[0][n-1];
}
