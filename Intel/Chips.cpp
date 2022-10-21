#include<bits/stdc++.h>
using namespace std;

int solve(int x, int y){
    int free = 1;
    if(x>=y && x%y==0)
        return x;

    x *= 10;
    while(x<y || x%y != 0){
        int c = y - x%y;
        if(floor(log10(c)+1) == free)
            return x+c;
        free++;
        x *= 10;
    }
    return x;
}

int main(){
    int x, y;
    cin>>x>>y;

    cout<<solve(x, y)<<endl;

    return 0;
}
