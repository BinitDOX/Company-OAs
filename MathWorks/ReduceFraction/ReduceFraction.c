#include<stdio.h>
using namespace std;

long gcd(long a, long b){
    return b==0 ? a : gcd(b, a%b);
}

void solve(string **s){
    int n = s.size();

    vector<long> frac(4);
    int j = 0;
    int num = 0;
    for(int i=0; i<=n; i++){
        if(s[i] != '/' && s[i] != '+' && s[i] != '\0'){
            num = num*10 + s[i]-'0';
        } else {
            frac[j++] = num;
            num = 0;
        }
    }

    long numer = frac[0]*frac[3] + frac[2]*frac[1];
    long demon = frac[1]*frac[3];
    long g = gcd(numer, demon);
    numer /= g;
    demon /= g;
    cout<<numer<<"/"<<demon<<endl;
}

int main(){
    int t;
    cin>>t;
    char **s;
    while(t--){
        string s;
        cin>>s;

        solve(s);
    }

    return 0;
}
