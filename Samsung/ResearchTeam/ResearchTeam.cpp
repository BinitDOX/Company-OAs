#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &mat, int n, vector<pair<int, int>> &locs, int k){
    queue<pair<int, pair<int, int>>> q;
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(n));

    int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for(int i=0; i<k; i++)
        q.push({i, locs[i]});

    int level = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            auto p = q.front();
            auto curr = p.second;
            q.pop();

            for(int d=0; d<4; d++){
                int r = curr.first + dir[d][0];
                int c = curr.second + dir[d][1];
                if(r>=0 && c>=0 && r<=n-1 && c<=n-1 && mat[r][c]==1){
                    bool flag = false;
                    for(int j=0; j<vis[r][c].size(); j++){
                        if(vis[r][c][j] == p.first){
                            flag = true;
                            break;
                        }
                    }

                    if(!flag){
                        vis[r][c].push_back(p.first);
                        q.push({p.first, {r, c}});
                        if(vis[r][c].size() == k)
                            return level+1;
                    }
                }
            }
        }
//        cout<<endl;
//        cout<<endl;
//
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                cout<<vis[i][j].size()<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;

        level++;
    }
    return -1;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        vector<pair<int, int>> locs(k);
        for(int i=0; i<k; i++){
            cin>>locs[i].first;
            cin>>locs[i].second;
            locs[i].first--;
            locs[i].second--;
        }

        vector<vector<int>> mat(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];

        cout<<solve(mat, n, locs, k)<<endl;

    }
    return 0;
}

