#include<bits/stdc++.h>
using namespace std;

int eval(int a, int b, char c){
    if(c == '/' && b == 0)
        return 1e8;

    switch(c){
        case '^': return pow(a, b);
        case '/': return a/b;
        case '*': return a*b;
        case '+': return a+b;
        case '-': return a-b;
    }
    return -1;
}

int precedence(char c){
    switch(c){
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
    }
    return 0;
}

int infixToPostfix(string ex, int x) {
    int n = ex.size();
    stack<char> s;
    stack<int> e;

    for(int i=0; i<n; i++){
        if(ex[i] == ' '){
            continue;
        } else if(isdigit(ex[i]) || ex[i] == 'x'){
            int num = 0;
            if(ex[i] == 'x'){
                e.push(x);
                continue;
            }
            while(i<n && isdigit(ex[i]))
                num = num*10 + ex[i++]-'0';
            i--;
            e.push(num);
        } else if(ex[i] == '('){
            s.push(ex[i]);
        } else if(ex[i] == ')'){
            while(s.top() != '('){
                int b = e.top();
                e.pop();
                int a = e.top();
                e.pop();
                char c = s.top();
                e.push(eval(a, b, c));
                s.pop();
            }
            s.pop();
        } else {
            while(!s.empty() && precedence(s.top()) >= precedence(ex[i])){
                int b = e.top();
                e.pop();
                int a = e.top();
                e.pop();
                char c = s.top();
                e.push(eval(a, b, c));
                s.pop();
            }
            s.push(ex[i]);
        }
    }

    while(!s.empty()){
        int b = e.top();
        e.pop();
        int a = e.top();
        e.pop();
        char c = s.top();
        e.push(eval(a, b, c));
        s.pop();
    }
    //cout<<e.top()<<endl;
    return e.top();
}

int solve(string &s, int p, int m){
    for(int i=0; i<INT_MAX; i++)
        if(infixToPostfix(s, i) % m == p)
            return i;
    return -1;
}

int main(){
    int p, m;
    string ex;
    cin>>ex;
    cin>>p>>m;

    cout<<solve(ex, p, m)<<endl;

    return 0;
}
