#include<bits/stdc++.h>
using namespace std;

int p = 1000;
int tsp(vector<pair<int, int>> &nodes, pair<int, int> s, pair<int, int> v, unordered_set<int> &vis, int n){
    if(vis.size() == n-1)
        return abs(s.first-v.first) + abs(s.second-v.second);

    int cost = 1e7;
    for(int i=2; i<n; i++){
        if(!(v.first == nodes[i].first && v.second == nodes[i].second) && vis.find(nodes[i].first*p + nodes[i].second) == vis.end()) {
            vis.insert(nodes[i].first*p + nodes[i].second);
            cost = min(cost, tsp(nodes, s, nodes[i], vis, n) + abs(nodes[i].first-v.first) + abs(nodes[i].second-v.second));
            vis.erase(nodes[i].first*p + nodes[i].second);
        }
    }
    return cost;
}

int solve(vector<pair<int, int>> &nodes, int n){
    unordered_set<int> vis;
    pair<int, int> s = nodes[0];
    vis.insert(s.first*p + s.second);

    return tsp(nodes, nodes[1], s, vis, n);
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        n+=2;
        vector<pair<int, int>> nodes(n);
        for(int i=0; i<n; i++){
            cin>>nodes[i].first;
            cin>>nodes[i].second;
        }

        cout<<solve(nodes, n)<<endl;

    }
    return 0;
}

