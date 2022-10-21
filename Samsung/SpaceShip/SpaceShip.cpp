#include <bits/stdc++.h>
using namespace std;

int moveShip(vector<vector<char>> mat, int i, int j, int n, int m, int bombs){
    if(i == 0)
        return mat[i][j]-'0';

    int left = 0;
    int right = 0;
    int stay = 0;
    int bomb = 0;

    if(mat[i-1][j] != '2')
        stay = moveShip(mat, i-1, j, n, m, bombs) + mat[i][j]-'0';

    if(j > 0 && mat[i-1][j-1] != '2')
        left = moveShip(mat, i-1, j-1, n, m, bombs) + mat[i][j]-'0';

    if(j < m-1 && mat[i-1][j+1] != '2')
        right = moveShip(mat, i-1, j+1, n, m, bombs) + mat[i][j]-'0';

    if(bombs){
        for(int q=max(0, i-5); q<i; q++)
            for(int r=0; r<m; r++)
                if(mat[q][r] == '2')
                    mat[q][r] = '0';

        bomb = moveShip(mat, i, j, n, m, bombs-1);
    }

    return max({left, right, stay, bomb});
}

int main() {
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<char>> mat(n, vector<char>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    cout<<moveShip(mat, n-1, m/2, n, m, k)-('S'-'0')<<endl;

	return 0;
}


