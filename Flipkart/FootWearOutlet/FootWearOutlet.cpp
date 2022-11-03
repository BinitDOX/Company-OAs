#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &mat, int n, vector<int> &wh, int k){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j)
                    mat[i][j] = 0;
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }

    int ans = 1e8;
    for(int i=0; i<k; i++){
        for(int j=i+1; j<k; j++){
            // cout<<wh[i]<<" -> "<<wh[j]<<" = "<<mat[wh[i]][wh[j]]<<endl;
            ans = min(ans, mat[wh[i]][wh[j]]);
        }
    }

    cout<<ans<<endl;
}

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> warehouses(k);
    for(int i=0; i<k; i++)
            cin>>warehouses[i];

    int e;
    cin>>e;
    vector<vector<int>> mat(n, vector<int>(n, 1e8));
    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;

        mat[u][v] = w;
        mat[v][u] = w;
    }

    solve(mat, n, warehouses, k);

    return 0; 
}








// Alternate:
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//    int n,k;
//    cin>>n>>k;
//    vector<int>warehouse(k);
//    int mp[n]={0};
//    for(int i=0;i<k;i++){
//       cin>>warehouse[i];
//       mp[warehouse[i]]++;
//    }
//    int edge;
//    cin>>edge;
//    int A[n+1][n+1];
//    for(int i=0;i<n;i++){
//       for(int j=0;j<n;j++){
//          A[i][j]=1e9;
//       }
//       A[i][i] = 0;
//    }
//    int a,b,c;
//    for(int i=0;i<edge;i++){
//       cin>>a>>b>>c;
//       A[a][b]=c;
//       A[b][a]=c;
//    }
//    int ans = 1e9;
//    for(int k=0;k<n;k++){
//       for(int i=0;i<n;i++){
//          for(int j=0;j<n;j++){
//             if(A[i][k] + A[k][j] < A[i][j]){
//                A[i][j] = A[i][k] + A[k][j];
//             }
//             if(i!=j and mp[i]==1 and mp[j]==1){
//                ans = min(ans, A[i][j]);
//             }
//          }
//       }
//    }
// if(ans==1e9)
//      ans=0;
//    cout<<ans<<endl;
// }