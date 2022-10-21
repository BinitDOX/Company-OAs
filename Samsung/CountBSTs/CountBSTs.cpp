int numTrees(int n) {
    long dp[n+1];
    long mod = 1e9+7;
    fill(dp, dp+n+1, 0);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] = (dp[i]+dp[j]*dp[i-1-j])%mod;
        }
    }
    return dp[n]%mod;
}