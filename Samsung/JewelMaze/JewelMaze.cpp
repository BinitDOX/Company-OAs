/*
There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. 
You want to pick up the jewels after getting into the maze through the entrance and before getting 
out of it through the exit. You want to get as many jewels as possible, but you don’t want to take 
the same passage you used once.
When locations of a maze and jewels are given, find out the greatest number of jewels you can get 
without taking the same passage twice, and the path taken in this case.

Input
There can be more than one test case in the input file. The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T ≤ 10 ).
In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. 
The maze is N×N square-shaped. From the second line through N lines, information of the maze is given.
“0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located 
on the upper-most left passage and the exit is located on the lower-most right passage. 
There is no case where the path from the entrance to the exit doesn’t exist.

Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the 
greatest number of jewels that can be picked up. Each test case must be output separately as a empty.
*/

#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> mat, int sr, int sc, int er, int ec, int dir[][2]){
    int save = mat[sr][sc];
    mat[sr][sc] = 3;

    if(sr == er && sc == ec){
        for(auto i : mat){
            for(auto j : i)
                cout<<j<<" ";
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        return mat[sr][sc] == 2;
    }

    int val = 0;
    for(int d=0; d<4; d++){
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];
        if(r>=0 && c>=0 && r<=er && c<=ec && mat[r][c] != 1 && mat[r][c] != 3){
            val = max(val, dfs(mat, r, c, er, ec, dir));
        }
    }
    mat[sr][sc] = save;
    return val + (mat[sr][sc] == 2);
}

int findjewels(vector<vector<int>> &mat, int n, int m){
    int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int jewels = dfs(mat, 0, 0, n-1, m-1, dir);

    return jewels;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    cout<<findjewels(mat, n, m);

    return 0; 
}


/*
8 9
0 0 0 1 0 0 1 2 1
0 1 2 1 2 1 1 0 1
0 1 1 1 1 1 0 0 1
0 0 0 0 0 0 2 0 1
0 1 1 1 2 0 0 0 0
0 0 0 1 0 1 0 1 1
1 1 0 1 0 1 0 0 1
2 0 0 1 0 1 0 2 0
*/