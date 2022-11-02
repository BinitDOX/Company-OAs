#include<bits/stdc++.h>
 
using namespace std;

int solve(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0)
            return 0;
    }    
    return 1;
}
 
int main(){

    int n;
    cin>>n;
    n++;
    int count=0; 
         
    for(int i = (n/2)+1;i<=n;++i){
        if(solve(i))
            count++;
    }
    cout<<count+1;

}

