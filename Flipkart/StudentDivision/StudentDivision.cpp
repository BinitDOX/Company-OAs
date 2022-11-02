#include<bits/stdc++.h>
using namespace std;


int countGroups(vector<int> &arr, int n, int g){
    int count = 0;

    for(int i=0; i<n; i++)
        count += ceil(arr[i]/(float)g);

    return count;
}

int solve(vector<int> &arr, int n, int k) {
    int sg = 1; // Starting group size
    int eg = 1e8; // Ending group size

    while(sg < eg){
        int mg = (sg+eg)/2;
        int rk = countGroups(arr, n, mg);
        if(rk <= k)
            eg = mg;
        else
            sg = mg+1;
    }
    return eg; // or sg
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
       
        cout<<solve(arr, n, k)<<endl;
    }
    return 0;
}
