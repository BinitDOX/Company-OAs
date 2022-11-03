#include<bits/stdc++.h>
using namespace std;

bool isSimilar(char c1, char c2){
    return (c1 == c2) || (c1=='a' && c2=='o') || (c1=='o' && c2=='a') || (c1=='t' && c2=='l') || (c1=='l' && c2=='t');
}

bool rec(string &t, int i, string &d, int j, int k, bool start, bool del, vector<vector<vector<vector<vector<int>>>>> &memo){
    int n = t.size();
    int m = d.size();

    if(i == n)
        return true;
    
    if(j == m)
        return false;

    if(memo[i][j][k][start][del] != -1)
        return memo[i][j][k][start][del];

    bool ret = false;
    if(isSimilar(t[i], d[j]))
        ret = ret || rec(t, i+1, d, j+1, k, true, del, memo);
    else if(k>0 && start)
        ret = ret || rec(t, i, d, j+1, k-1, true, del, memo);
    
    if(!del)
        ret = ret || rec(t, i+1, d, j, k, start, true, memo);
    if(!start)
        ret = ret || rec(t, i, d, j+1, k, false, del, memo);
    return memo[i][j][k][start][del] = ret;
}


int solve(vector<string> &ts, string &ds, int k){
    int c = 0;

    for(string &t : ts){
        vector<vector<vector<vector<vector<int>>>>> memo(t.size()+1, vector<vector<vector<vector<int>>>>(ds.size()+1, vector<vector<vector<int>>>(k+1, vector<vector<int>>(2, vector<int>(2, -1)))));
        c +=  rec(t, 0, ds, 0, k, false, false, memo);
    }

    return c;
}
    


int main(){
    int n;
    cin>>n;
    vector<string> tickets(n);

    for(int i=0;i<n;i++)
        cin>>tickets[i];
    
    string drawString;
    cin>>drawString;

    int tolerance;
    cin>>tolerance;

    cout<<solve(tickets, drawString, tolerance);
}

/*
5
abcdl aob acld aobocd aabo
aabacdt
1
*/

/*
5
droqwl slingfo oliketss oticelss drawhhhstring
drawstringandatickets
3
*/


// bool rec(string &t, int i, string &ds, int j, int k, bool del){
//     int n = t.size();
//     int m = ds.size();

//     if(i == n)
//         return true;
    
//     if(i>n || j>m)
//         return false;

//     // if(i<n && j<m)
//     //     cout<<t[i]<<" "<<ds[j]<<endl;

//     if(t[i] == ds[j]){
//         if(rec(t, i+1, ds, j+1, k, del))
//             return true;
//     } else {
//         if(t[i] == 'a' && 'o' == ds[j])
//             if(rec(t, i+1, ds, j+1, k, del))
//                 return true;
//         if(t[i] == 'o' && 'a' == ds[j])
//             if(rec(t, i+1, ds, j+1, k, del))
//                 return true;
//         if(t[i] == 't' && 'l' == ds[j])
//             if(rec(t, i+1, ds, j+1, k, del))
//                 return true;
//         if(t[i] == 'l' && 't' == ds[j])
//             if(rec(t, i+1, ds, j+1, k, del))
//                 return true;
//         if(t[i] == 'l' && 't' == ds[j])
//             if(rec(t, i+1, ds, j+1, k, del))
//                 return true;
//         if(!del)
//             if(rec(t, i+1, ds, j, k, true))
//                 return true;
//         if(k > 0)
//             if(rec(t, i, ds, j+1, k-1, del))
//                 return true;
//     }
//     return false;
// }

// int solve(vector<string> &ts, string &ds, int k){
//     int c = 0;

//     for(string &t : ts){
//         for(int i=0; i<ds.size(); i++){
//             bool f = rec(t, 0, ds, i, k, false);
//             c += f;
//             if(f) break;
//             //cout<<endl;
//         }
//         //cout<<endl;
//     }

//     return c;
// }