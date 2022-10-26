#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n, int m){
    int ans = 1e7;

    for(int i=m-1; i<n; i++){
        int diff = abs(arr[i]-arr[i-(m-1)]);
        int dist = min(abs(arr[i]), abs(arr[i-(m-1)]));
        ans = min(ans, diff+dist);
    }

    cout<<ans<<endl;
}

int main(){
    int n, m;
    cin>>n>>m;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    solve(arr, n, m);

    return 0; 
}

/*
5 3
-50 -40 -30 -10 -5

5 3
-35 -10 10 20 40

3 2
10 20 25
*/