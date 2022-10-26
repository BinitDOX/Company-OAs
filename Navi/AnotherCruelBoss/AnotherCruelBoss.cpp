#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    int dp[n+1];

    dp[0] = 1; // Ways: -
    dp[1] = 1; // Ways: 1
    dp[2] = 1; // Ways: 1 1
    // dp[3] = 2; // Ways: 1 1 1 | 3

    for(int i=3; i<=n; i++)
        dp[i] =  dp[i-1] + dp[i-3];

    return dp[n];
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        cout<<solve(n)<<endl;
    }

    return 0; 
}