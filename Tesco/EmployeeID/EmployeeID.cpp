/*
A company recruits N employees and each of the employees is given an ID code. On day 1 it is 5000+i, where i is k for the k'th employee (1 for 1st employee, 2 for 2nd... N for nth). From day 2 the id is day(n) = day(n-1) + 5000 + n-1, where n is n'th day. 
You'll be given the number of employees and a random id number as input and you have to output the number of which employee the id belongs to.

Ex input - 10, 15006

3rd employee
day 1, 5003
day 2, 10004
day 3, 15006
So the output should be 3(3rd employee)
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int n, int id){
    vector<int> ans;
    for(int d=0; d<=n; d++){
        int tid = id - d*5000 - d*(d+1)/2 - 5000; 
        if(tid < 0)
            break;
        if(tid <= n)
            ans.push_back(tid);
    }

    for(auto &x : ans)
        cout<<x<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, id;
        cin>>n>>id;

        solve(n, id);
    }

    return 0; 
}