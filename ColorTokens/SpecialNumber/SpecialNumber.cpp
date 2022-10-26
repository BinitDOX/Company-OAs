#include<bits/stdc++.h>
using namespace std;

int minCost(long long n, long long icost, long long dcost){
    vector<int> prime = {3, 5, 7};
    long long mc = 1e8;

    for(int i=0; i<prime.size()-1; i++){
        for(int p=1; p<32; p++){
            long long p1x1 = pow((long long)prime[i], p);
            if(p1x1 > INT_MAX)
                break;
            for(int j=i+1; j<prime.size(); j++){
                for(int q=1; q<32; q++){
                    long long p2x2 = pow((long long)prime[j], q);
                    if(p2x2 > INT_MAX)
                        break;

                    long long s = p1x1 + p2x2;
                    if(s > INT_MAX)
                        break;

                    mc = min({mc, (n>s && (n-s)*icost<=INT_MAX?(n-s)*icost:(long long)1e7), (n<=s && (s-n)*dcost<=INT_MAX?(s-n)*dcost:(long long)1e7)});
                    //cout<<p1x1<<" "<<p2x2<<" "<<mc<<" "<<endl;
                }
            }
        }
    }
    return mc;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, icost, dcost;
        cin>>n>>icost>>dcost;

        cout<<minCost(n, icost, dcost)<<endl;
    }

    return 0; 
}