#include<bits/stdc++.h>
using namespace std;

//vector<vector<int>> spiralize(vector<int> &arr, int r, int c){
//    int sr = 0;
//    int sc = 0;
//    int er = r-1;
//    int ec = c-1;
//    int x = 0;
//
//    vector<vector<int>> mat(r, vector<int>(c));
//
//    while(sr <= er && sc <= ec){
//
//        if(sr <= er && sc <= ec){
//            for(int i=sc; i<=ec; i++)
//                mat[sr][i] = arr[x++];
//            sr++;
//        }
//        #define loop 4
//        static int loop;
//        if(sr <= er && sc <= ec){
//            for(int i=sr; i<=er; i++)
//                mat[i][ec] = arr[x++];
//            ec--;
//        }
//
//        if(sr <= er && sc <= ec){
//            for(int i=ec; i>=sc; i--)
//                mat[er][i] = arr[x++];
//            er--;
//        }
//
//        if(sr <= er && sc <= ec){
//            for(int i=er; i>=sr; i--)
//                mat[i][sc] = arr[x++];
//            sc++;
//        }
//    }
//    return mat;
//}

vector<vector<int>> seperateIntoBounries(vector<int> &arr, int r, int c){
    int n = arr.size();
    vector<vector<int>> boundries;
    vector<int> boundry;
    r-=2;
    int offset = 0;

    for(int i=0; i<n;){
        if(i-offset < 2*(r+c)){
            boundry.push_back(arr[i++]);
        } else {
            r -= 2;
            c -= 2;
            r = max(0, r);
            c = max(0, c);
            offset = i;
            boundries.push_back(boundry);
            boundry = vector<int>();
        }
    }
    boundries.push_back(boundry);
    return boundries;
}

void performRotations(vector<vector<int>> &boundries, int k){
    int n = boundries.size();
    for(int i=0; i<n-1; i++) // Notice n-1 here, don't rotate middle most
        rotate(boundries[i].begin(), boundries[i].begin()+k, boundries[i].end());
}

vector<int> flatten(vector<vector<int>> &boundries){
    int n = boundries.size();
    vector<int> flat;

    for(auto boundry : boundries)
        for(auto b : boundry)
            flat.push_back(b);
    return flat;
}

void solve(vector<int> &arr, int r, int c, int k){


    vector<vector<int>> boundries = seperateIntoBounries(arr, r, c);
    performRotations(boundries, k);
    vector<int> flat = flatten(boundries);
    //vector<vector<int>> mat = spiralize(flat, r, c);

    arr = flat;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int r, c, k;
    cin>>r>>c>>k;

    solve(arr, r, c, k);

    for(auto &i : arr)
            cout<<i<<" ";

    return 0;
}

// Sample Input: (n, list, r, c, k)
// 56
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 201 202 203 204 205 206 207 208 209 210 301 302
// 7 8 4
