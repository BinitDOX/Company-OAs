/*
Problem Statement

Noah is a traveller who wants to travel to different places. He knows in a unique pattern between various cities. But here’s a catch, he wants to travel in a unique pattern between various cities. Since he’s having a hard time choosing the path he wants to travel, he has decided that starting from the first city (s1) he’ll move to the next city which is closest to it (s2) and then he’ll move to the next city closest to it and so on.
Given the number of paths and the closest cities, print the order in
which Noah has to travel. Assume that the city which comes first (last
line of Input) is closest to him.

Input Format

The first line is an integer which denotes the number of paths P

• The next P lines take two space separated strings s1 and s2

• The last line after P lines takes a single string as input which
denotes the city the traveller visits first

Constraints

• 1 <= P <= 100

1<= length of each string <= 100

Output Format

• The output consists of a single string in each line which denotes
the path the traveller has to travel

Note: s1 to s2 denotes a path from City A to City B but NOT from city B to city A

Evaluation Parameters

Sample Input

5
Bangalore Hyderabad
Bangalore Chennai
Hyderabad Mumbai
Hyderabad Delhi
Chennai Kerala
Bangalore

Sample Output-
Bangalore
Hyderabad
Mumbai
Delhi
Chennai
Kerala

EXECUTION TIME LIMIT

2 seconds
*/


#include<bits/stdc++.h>
using namespace std;

void solve(unordered_map<string, vector<string>> &adj, string v, unordered_map<string, bool> &vis){
    cout<<v<<endl;
    vis[v] = true;

    for(auto u : adj[v])
        if(!vis[u])
            solve(adj, u, vis);
}

int main(){
    int n;
    cin>>n;

    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> vis;
    for(int i=0; i<n; i++){
        string v;
        string u;
        cin>>v>>u;
        adj[v].push_back(u);
    }

    string s;
    cin>>s;

    solve(adj, s, vis);

    return 0; 
}
