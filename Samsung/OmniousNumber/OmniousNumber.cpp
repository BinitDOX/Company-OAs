/*
Company  A  is discarding product numbers that contain few specific digits a specific number of time or 
more than that. You are given a range and you need to find product numbers that are possible.
Example-
Range: 24 to 12943
Numbers that should not come: 1, 3, 5
Number of times these number should not occur: 3 or more
In above case all two digit numbers are valid.
In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid.
In four digit: All the numbers containing above 3 digit numbers are not valid.
Eg: 11223 is not valid, 11222 is valid.
*/

#include <bits/stdc++.h>
using namespace std;

int numberOminous(int s, int e, int k, int badnums[], int n){
    int goodcount = 0;

    for(int i = s; i <= e; i++){
        int temp = i;
        int dmap[10] = {0};
        while(temp){
            dmap[temp%10]++;
            temp /= 10;
        }
        
        int badcount = 0;
        for(int i=0; i<n; i++)
            badcount += dmap[badnums[i]];

        if(badcount < k){
            goodcount++;
        } else {
            cout<<i<<" ";
        }
    }
    return goodcount;
}

int main() {
    int start, end, badCount;
    cin >> start >> end >> badCount;

    int n;
    cin >> n;

    int badNums[n];
    for(int i=0; i<n; i++)
        cin >> badNums[i];

    cout << numberOminous(start, end, badCount, badNums, n) << endl;

    return 0;
}