#include<bits/stdc++.h>
using namespace std;

struct PQNode {
    int pi;
    int at;
    int bt;

    PQNode(int i, int a, int b){
        pi = i;
        at = a;
        bt = b;
    }

    operator<(PQNode const &pqn) const {
        return bt == pqn.bt ? pi > pqn.pi : bt > pqn.bt;
    }
};

vector<int> solve(vector<pair<int, int>> &orders, int n, int k, int w){
    priority_queue<PQNode> pq;
    vector<int> costs(n);

    int ct = 0;
    int i = 0;
    int cost = 0;

    while(i<n || !pq.empty()){
        if(!pq.empty()){
            PQNode p = pq.top();
            pq.pop();

            int cost = k*p.bt - (ct-p.at)*w;
            costs[p.pi] = (cost);

            ct += p.bt;
        } else {
            ct = orders[i].first;
        }

        while(i<n && ct >= orders[i].first){
            pq.push(PQNode(i, orders[i].first, orders[i].second));
            i++;
        }
    }

    return costs;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k, w;  // k=cost/min, w=discount/min
        cin>>n>>k>>w;

        vector<pair<int, int>> orders(n);
        for(int i=0; i<n; i++)
            cin>>orders[i].first>>orders[i].second;

        cout<<endl;
        vector<int> costs = solve(orders, n, k, w);
        for(auto c : costs)
            cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}

/*
1
5 10 1
3 5
4 2
4 1
10 15
15 2
*/

/*
2
5 4 0
2 2
6 1
8 5
10 1
14 1
5 3 3
3 3
5 2
*/
