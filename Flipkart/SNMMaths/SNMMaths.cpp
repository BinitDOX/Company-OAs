#include<bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, int M){
    long long sol = 1;

    while(b){
        if(b & 1){
            sol = (sol * a) % M;
        }
        a = (a * a) % M;
        b = b >> 1;
    }
    return sol % M;
}

int main(){
    int P, N, M, S;
    cin >> S >> N >> M;
    long long res1 = solve(S, N, 10);
    long long res2 = solve(res1, M, 1000000007);
    cout<< res2;

}
