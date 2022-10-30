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