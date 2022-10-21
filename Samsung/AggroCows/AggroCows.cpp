// https://www.spoj.com/problems/AGGRCOW/cstart=10

// You are given an array of integers which represents positions available and an integer c(cows).
// Now you have to choose c positions such that the minimum difference between cows is maximized.


// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other
// once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the
// cows to the stalls, such that the minimum distance between any two of them is as large as
// possible. What is the largest minimum distance?

// AC
#include<bits/stdc++.h>
using namespace std;

int countCows(int pos[], int n, int d){
    int cows = 1;
    int dist = 0;
    for(int i=1; i<n; i++){
        dist += pos[i] - pos[i-1];
        if(dist >= d){
            dist = 0;
            cows++;
        }
    }
    return cows;
}

int aggrocows(int pos[], int n, int k){
    sort(pos, pos+n);

    int sd = 0;
    int ed = pos[n-1] - pos[0];

    while(sd < ed){
        int md = ceil((sd + ed)/2.0);
        int ck = countCows(pos, n, md);
        if(ck >= k)
            sd = md;
        else
            ed = md-1;
    }
    return sd;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        int pos[n];
        for(int i=0; i<n; i++)
            cin>>pos[i];

        cout<<aggrocows(pos, n, k)<<endl;
    }

    return 0; 
}