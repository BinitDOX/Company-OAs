#include<bits/stdc++.h>
using namespace std;

bool rec(string &t, int i, string &ds, int j, int k, bool del){
    int n = t.size();
    int m = ds.size();

    if(i == n)
        return true;
    
    if(i>n || j>m)
        return false;

    // if(i<n && j<m)
    //     cout<<t[i]<<" "<<ds[j]<<endl;

    if(t[i] == ds[j]){
        if(rec(t, i+1, ds, j+1, k, del))
            return true;
    } else {
        if(t[i] == 'a' && 'o' == ds[j])
            if(rec(t, i+1, ds, j+1, k, del))
                return true;
        if(t[i] == 'o' && 'a' == ds[j])
            if(rec(t, i+1, ds, j+1, k, del))
                return true;
        if(t[i] == 't' && 'l' == ds[j])
            if(rec(t, i+1, ds, j+1, k, del))
                return true;
        if(t[i] == 'l' && 't' == ds[j])
            if(rec(t, i+1, ds, j+1, k, del))
                return true;
        if(t[i] == 'l' && 't' == ds[j])
            if(rec(t, i+1, ds, j+1, k, del))
                return true;
        if(!del)
            if(rec(t, i+1, ds, j, k, true))
                return true;
        if(k > 0)
            if(rec(t, i, ds, j+1, k-1, del))
                return true;
    }
    return false;
}

int solve(vector<string> &ts, string &ds, int k){
    int c = 0;

    for(string &t : ts){
        for(int i=0; i<ds.size(); i++){
            bool f = rec(t, 0, ds, i, k, false);
            c += f;
            if(f) break;
            //cout<<endl;
        }
        //cout<<endl;
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


// Alternate?
// bool solve(string &str, string &test, int n, int m, int K, bool mark, bool del){
//     if(m==0){
//         return true;
//     }
//     if(n==0){
//         return false;
//     }
//     bool res=false;
//     if(str[n-1] ==test[m-1]){  
//         res=res || solve(str,test,n-1,m-1,K,true,del);
//     }
//     else if(K>0 && mark==true){ 
//         res=res || solve(str,test,n-1,m,K-1,true,del);
//     }
//     if(del==false){ 
//         res=res || solve(str,test,n,m-1,K,mark,true);
//     }
//     if(mark==false){ 
//         res=res || solve(str,test,n-1,m,K,false,del);
//     }
//     return res;
// }


// int winTkt(vector<string> ticketList, string drawString, int tolerance)
// {
//     int count = 0;
//     for(int i=0;i<ticketList.size();i++) {
//         for(int j=0;j<ticketList[i].size();j++) {
//             if(ticketList[i][j]=='o'){
//                 ticketList[i][j]='a';
//             }
//             if(ticketList[i][j]=='l'){ 
//                 ticketList[i][j]='t';   
//             }
//         }
//     }
//     int n = drawString.size();
//     for(int z = 0; z < ticketList.size(); z++)
//     {   
//         string ticket = ticketList[z];
//         count+=solve(drawString,ticket,n,ticket.size(),tolerance,false,false);
//     }
//     return count;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<string>v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     string drawString;
//     cin>>drawString;
//     int tolerance;
//     cin>>tolerance;
//     cout<<winTkt(v,drawString,tolerance);
// }