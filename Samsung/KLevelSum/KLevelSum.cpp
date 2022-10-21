#include<bits/stdc++.h>
using namespace std;

int klvlsum(string &s, int k){
    int n = s.size();
    int level = -1;
    int sum = 0;

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            level++;
        } else if(s[i] == ')'){
            level--;
        } else {
            int num = 0;
            while(isdigit(s[i]))
                num = num*10 + s[i++]-'0';
            i--;

            if(level == k)
                sum += num;
        }
    }
    return sum;
}

int main(){
    int k;
    string s;
    cin>>s>>k;

    cout<<klvlsum(s, k);

    return 0;
}