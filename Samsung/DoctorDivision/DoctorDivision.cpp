/*
A Doctor travels from a division to other division where divisions are connected like a graph (directed graph)
and the edge weights are the probabilities of the doctor going from that division to other connected division
but the doctor stays 10 mins at each division. Given a time T, you have to determine the division at which doctor
will be found at time T. The doctor moves in the direction of highest probability.
Input is number of test cases followed by number of nodes, edges, time after which we need find the division in
which he will be there then the edges starting point, end point, probability.

Note: If he reach a point where there are no further nodes then he leaves the lab after 10 mins
the travelling time is not considered and during that 10 min
    at 10th min he will be in next division

input:
N E T
U1 V1 P1
U2 V2 P2
.. .. ..
UE VE PE
START_DIVISION
0<= U,V <N
*/

#include<bits/stdc++.h>
using namespace std;


void docdiv(vector<vector<float>> &mat, int n, int v, int t){
    int cn = v;  // current node
    int ct = 0;  // current time
    
    while(ct < t){
        int nn = -1; // next node
        int mp = 0; // max probability

        for(int i=0; i<n; i++){
            if(mat[cn][i] > mp){
                mp = mat[cn][i];
                nn = i;
            }
        }
        if(nn == -1){
            cout<<"(+) Doctor exits lab"<<endl;
            return;
        }

        cn = nn;
        ct += 10;

        cout<<"(+) Doctor at division "<<cn<<" at "<<ct<<endl; 
    }
}

int main(){
    int n, e, t;
    cin>>n>>e>>t;

    vector<vector<float>> adj(n, vector<float>(n));
    for(int i=0; i<e; i++){
        int u, v, p;
        cin>>u>>v>>p;
        adj[u][v] = p;
    }

    int v;
    cin>>v;

    docdiv(adj, n, v, t);

    return 0; 
}


/*

5 7 6
0 1 4
0 2 3
1 2 1
1 4 4 
4 3 3
3 2 5
2 0 1

*/