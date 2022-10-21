/*
    You are given an old touch smartphone numbers having dial pad and calculator app. The goal is to type a number on dial-pad. Calculator have 1-9 and +, -, * , /, = as operations. But as the phone is old, some of the numbers and some operations can't be touched. But you can always make a number using other numbers and operations. There could be multiple ways of making a number. You have to find minimum operation for making a number.
    For ex: lets say 1,4,6,7,8,9 works and +,-,* works. 2,3,5 and / doesn't work.
    If you have to type 18-> 2 operations. (Each touch is considered an operation).
    If you have to type 5 -> '1+4=' that requires 4 operations. There could be other ways to make '5'.
    The goal is to find minimum operations.
*/

#include<bits/stdc++.h>
using namespace std;



int evaluate(int a, int b, char c){
    if(b == 0 && c == '/')
        return 1e7;
    switch(c){
        case '^': return pow(a, b);
        case '/': return a/b;
        case '*': return a*b;
        case '+': return a+b;
        case '-': return a-b;
    }
    return 1e7;
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

int calculate(string ex) {
    int n = ex.size();
    stack<char> s;
    stack<int> e;

    for(int i=0; i<n; i++){
        if(ex[i] == ' '){
            continue;
        } else if(isdigit(ex[i])){
            long num = 0;
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
                e.push(evaluate(a, b, c));
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
                e.push(evaluate(a, b, c));
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
        e.push(evaluate(a, b, c));
        s.pop();
    }
    
    return e.top();
}


int calculator(int digit[], int n, char operators[], int m, int limit, int target){
    queue<string> q;

    for(int i=0; i<n; i++)
        if(digit[i])
            q.push(to_string(digit[i]));

    int level = 1;
    while(!q.empty()){
        int size = q.size();
        for(int l=0; l<size; l++){
            string c = q.front();
            q.pop();

            int x = isdigit(c.back()) ? calculate(c) : -1;
            //cout<<c<<"="<<x<<" ";
            if(isdigit(c.back()) && x == target){
                cout<<"[F]: "<<c<<" ";
                for(auto e : c)
                    if(!isdigit(e))
                        return level+1;
                return level;
            }

            if(limit < level)
                return -1;

            for(int i=0; i<n; i++)
                q.push(c+to_string(digit[i]));

            for(int i=0; i<m; i++)
                if(isdigit(c.back()))
                    q.push(c+string(1, operators[i]));
        }
        level++;
        //cout<<endl;
    }
    return -1;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, m, limit;
        cin>>n>>m>>limit;

        int digits[n];
        char operators[m];
        int target;

        for(int i=0; i<n; i++)
            cin>>digits[i];

        for(int i=0; i<m; i++)
            cin>>operators[i];

        cin>>target;

        cout<<calculator(digits, n, operators, m, limit, target)<<endl;
    }
    return 0;
}

/*
5
5 3 5
1 2 4 6 0
+ - *
5
5 3 5
1 2 4 6 0
+ - *
14
6 4 5
1 2 4 6 9 8
+ - * /
91
6 3 10
0 1 3 5 7 9
+ - /
28
5 2 10
1 2 6 7 8
- *
981
*/
