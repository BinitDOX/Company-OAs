#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
 
	vector<vector<int>> dir[] = {{{0,1}, {1,0}, {-1,0}, {0,-1}}, 
	    {{1,0}, {-1,0}}, {{0,1}, {0,-1}}, {{0,1},{-1,0}},
	    {{0,1}, {1,0}}, {{1,0}, {0,-1}}, {{-1,0}, {0,-1}}};
 
	while(t--){
		int n, m;
		int sr, sc, len;
		cin>>n>>m>>sr>>sc>>len;
 
		vector<vector<int>> mat(n, vector<int>(m));
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin>>mat[i][j];
 
		queue<pair<int, int>> q;
		q.push({sr, sc});
 
		if(mat[sr][sc] == 0){
			cout<<0<<endl;
			continue;
		}
		
		int level = 0;
		int ans = 0;
 
		while(!q.empty()){
 
			if(level == len)
				break;
			
			int size = q.size();
			for(int i=0; i<size; i++){
				auto p = q.front();
				q.pop();
 
				int sr = p.first;
				int sc = p.second;
 
				if(mat[sr][sc] == 0)
					continue;
 
				vector<vector<int>> dirs = dir[mat[sr][sc]-1];
				mat[sr][sc] = 0;
				ans++;
				
				for(int i=0; i<dirs.size(); i++){
					int r = sr + dirs[i][0];
					int c = sc + dirs[i][1];
 
					if(r>=0 && c>=0 && r<n && c<m && mat[r][c] != 0){
						bool flag = false;
						for(auto d : dir[mat[r][c]-1]){
							int pr = r + d[0];
							int pc = c + d[1];
							if(sr == pr and sc == pc)
								flag = true;
						}
						if(flag) q.push({r, c});
					}
				}
			}
			level++;
		}
		cout<<ans<<endl;
	}
	return 0;
}