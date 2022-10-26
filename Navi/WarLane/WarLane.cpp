#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int l){
    int minr = 1;
    sort(arr, arr+n);

    for(int i=1; i<n; i++)
        minr = max((int)ceil((arr[i]-arr[i-1])/2.0), minr);
    
    minr = max(minr, abs(0-arr[0]));
    minr = max(minr, abs(l-arr[n-1]));
    return minr;
}

int main(){
    int n, l;
    cin>>n>>l;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<solve(arr, n, l)<<endl;

    return 0; 
}