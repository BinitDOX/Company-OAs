#include<bits/stdc++.h>
using namespace std;

string solve(string &s){
    int n = s.size();
    unordered_map<char, char> um;

    int i = 0;
    for(auto &c : s)
        if(um.find(c) == um.end())
            um[c] = 'A' + i++;
        
    for(int i=0; i<n; i++)
        s[i] = um[s[i]];

    return s;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        cout<<solve(s)<<endl;
    }

    return 0; 
}