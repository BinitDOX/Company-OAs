#include<bits/stdc++.h>
using namespace std;


struct Node{
    int x;
    int y;
    int c;

    Node(){}

    Node(int x, int y, int c){
        this->x = x;
        this->y = y;
        this->c = c;
    }

    bool operator<(Node const &p) const {
        return c > p.c;
    }
};


int dikstra(unordered_map<int, unordered_map<int, Node>> &adj, int sx, int sy, int dx, int dy, int p){
    unordered_map<int, int> dist;
    priority_queue<Node> pq;

    for(auto x : adj)
        dist[x.first] = 1e7;

    pq.push(Node(sx, sy, 0));
    dist[0*p+0] = 0;

    while(!pq.empty()){
        Node v = pq.top();
        pq.pop();

        for(auto x : adj[v.x*p + v.y]){
            Node u = x.second;
            if(dist[v.x*p + v.y] + u.c < dist[u.x*p + u.y]){
                dist[u.x*p + u.y] = dist[v.x*p + v.y] + u.c;
                pq.push(u);
            }
        }
    }

    return dist[dx*p + dy];
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int sx, sy;
        int dx, dy;
        int p = 1e5;

        cin>>sx>>sy;
        cin>>dx>>dy;

        int n;
        cin>>n;

        unordered_map<int, unordered_map<int, Node>> adj;
        adj[sx*p + sy];
        adj[dx*p + dy];

        for(int i=0; i<n; i++){
            int x1, y1, x2, y2, c;
            cin>>x1>>y1>>x2>>y2>>c;

            adj[x1*p+y1][x2*p+y2] = Node(x2, y2, c);
            adj[x2*p+y2][x1*p+y1] = Node(x1, y1, c);
        }

        for(auto i : adj)
            for(auto j : adj)
                if(adj[i.first].find(j.first) == adj[i.first].end())
                    adj[i.first][j.first] = Node(j.first/p, j.first%p, abs(i.first/p - j.first/p)+ abs(i.first%p - j.first%p));

        cout<<dikstra(adj, sx, sy, dx, dy, p)<<endl;

        return 0;
    }

}

