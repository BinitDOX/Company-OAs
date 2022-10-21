#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &adj, int v, vector<bool> &vis, vector<int> &compo){
	vis[v] = true;
	compo.push_back(v);

	for(auto u : adj[v])
        if(!vis[u])
            dfs(adj, u, vis, compo);
}


int solve(int v, int e, vector<int> &ff, vector<int> &ft, vector<int> &fw){
    unordered_map<int, vector<vector<int>>> gmap;
    vector<vector<int>> cmap(v+1, vector<int>(v+1));

    for(int i=0; i<e; i++){
        if(gmap.find(fw[i]) == gmap.end())
			gmap[fw[i]] = vector<vector<int>>(v+1, vector<int>());
		gmap[fw[i]][ff[i]].push_back(ft[i]);
    }

    for(auto &x : gmap){
		vector<bool> vis(v+1);
		for(int i=1; i<=v; i++){
			if(!x.second[i].empty() && !vis[i]){
				vector<int> compo;
				dfs(x.second, i, vis, compo);
                for(int i=0; i<compo.size()-1; i++)
                    for(int j=i+1; j<compo.size(); j++)
                        cmap[compo[i]][compo[j]]++;
			}
		}
	}

    int ans = 0;
	int len = 0;
	for(int i=1; i<=v; i++){
		for(int j=1; j<=v; j++){
			if(cmap[i][j]>len){
				len = cmap[i][j];
				ans = i*j;
			} else if (cmap[i][j]==len){
				ans = max(ans, i*j);
			}
		}
	}
	return ans;
}


int main() {
	int v,e;
	cin>>v>>e;
	vector<int> ff(e);
	vector<int> ft(e);
	vector<int> fw(e);

	for(int i=0;i<e;i++){
		cin>>ff[i];
		cin>>ft[i];
		cin>>ft[i];
	}

	cout<<solve(v, e, ff, ft, fw);

	return 0;
}
