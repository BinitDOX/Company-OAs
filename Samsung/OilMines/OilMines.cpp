/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines
having values. You have to distribute the mines to "n" companies in fair manner.
Remember the companies can have oil mines adjacent to each other and not in between
of each other. After distributing them compute the difference of oil mines from the
company getting highest and company getting lowest. This number should be minimum.
(then only the distribution can be termed as fair)

  Example
  Input
  2
  2 4
  6 13 10 2
  2 4
  6 10 13 2

  output
  5
  1

https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/

#include<bits/stdc++.h>
using namespace std;

long long  reqPainters(int arr[], int si, int ei, int n, long long ttime, int tpou){
    long long p = 1;
    long long t = 0;
    for(int i=si; i<=ei; i++){
        t += arr[i%n] * tpou;
        if(t > ttime){
            p++;
            t = arr[i%n] * tpou;
        }
    }
    return p;
}


// Extra for this Oil Problem:
long long minmaxDifference(int arr[], int si, int ei, int n, long long ttime){
    long long t = 0;
    long long maxd =-1e8;
    long long mind = 1e8;
    for(int i=si; i<=ei; i++){
        t += arr[i%n];
        if(t > ttime){
            maxd = max(maxd, abs(t-arr[i%n]));
            mind = min(mind, abs(t-arr[i%n]));
            t = arr[i%n];
        }
    }
    return max(maxd, t) - min(mind, t);
}

long long minTime(int arr[], int n, int numPainters, int tpou=1){ // time to paint one unit
    int mint = 0; // minTime
    long long unsigned maxt = 0;

    for(int i=0; i<n; i++){
        mint = max(mint, arr[i]);
        maxt += arr[i] * tpou;
    }

    long long st = mint;
    long long et = maxt;
    while(st < et){
        long long mt = st + (et-st) / 2;
        long long rp = min(reqPainters(arr, 0, n-1, n, mt, tpou), reqPainters(arr, 1, n, n, mt, tpou));
        if(rp <= numPainters){
            et = mt;
        } else {
            st = mt + 1;
        }
    }
    cout<<et<<endl;
    return min(minmaxDifference(arr, 0, n-1, n, et), minmaxDifference(arr, 1, n, n, et));
}

int main(){
    int t;
    cin>>t;
    while(t--){

        int n, m;
        cin>>n>>m;

        int arr[m];
        for(int i=0; i<m; i++)
            cin>>arr[i];

        cout<<minTime(arr, m, n)<<endl;
    }
    return 0; 
}