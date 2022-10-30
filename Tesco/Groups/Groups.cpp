/*
There are N users named 2....N + 1 in a social media platform
Users cannot add friends on their own. Two users are friends if one is divisible by other (Ex: 2 and 4 are friends, 3 and 9 are friends etc)
Groups are being formed where all group members are either direct friends or friends of friends
(Ex: If N = 10, Groups that can be formed are
G1 - {2, 3, 4, 5, 6, 8, 9, 10}
G2 - {7}
G3 - {11})
Given N, find total number of groups possible.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n < 4)
        return n-1;

    int count = 0;
    vector<bool> sieve(n+1);

    for(int i=2; i<n+1; i++){
        if(sieve[i])
            continue;
        
        if(i*2 >= n+1)
            count++;

        for(int j=i; j*i<n+1; j++)
            sieve[i*j] = true;
    }
    return count+1;
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