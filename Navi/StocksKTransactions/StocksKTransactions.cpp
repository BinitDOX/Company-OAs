int maxProfit(int k, int n, int arr[]) {
    int dp[n+1][k+1][2];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(i==0 || j==0){
                dp[i][j][0] = 0;
                dp[i][j][1] = -1e7;
                continue;
            }
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+arr[i-1]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-arr[i-1]);
        }
    }
    return dp[n][k][0];
}


// Space Optimized:

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(n == 0) return 0;

    vector<int> buy(k+1, -1e6);
    vector<int> sell(k+1, 0);

    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            sell[j] = max(sell[j], buy[j] + prices[i]);
            buy[j] = max(buy[j], sell[j-1] - prices[i]);
        }
    }
    return sell[k];
}