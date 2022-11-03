#include<bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2){
    return (s1.size()==s2.size() && (s1+s1).find(s2)!=string::npos);
}

int main(){
    string s1, s2;
    cin>>s1>>s2;

    cout<<solve(s1, s2);

    return 0;
}