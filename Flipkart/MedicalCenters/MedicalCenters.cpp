#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr) {
    int n = arr.size();

    priority_queue<int> pq(arr.begin(), arr.end());

    int block = -1;
    int ans = 0;
    while(!pq.empty()){
        int p = pq.top();
        pq.pop();

        p--;
        ans++;

        if(block > 0)
            pq.push(block);
        block = p;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
   
    cout<<solve(arr)<<endl;
    return 0;
}



// Alternative:
/*
#include<bits//stdc++.h>
using namespace std;
#define INF 1e8
int answer(vector<int> city) {
        priority_queue<int> pq;
        for(auto p:city) pq.push(p);
        int ans=0;
        int p=0;
        while(pq.size()>1)
        {
            int  c1=pq.top();
            pq.pop();
            int  c2=pq.top();
            pq.pop();
            ans++;
            c2--;
            ans++;
            c1--;
            if(c1) pq.push(c1);
            if(c2) pq.push(c2);
        }
        if(!pq.empty()) ans++;
        return ans;
    }

int main()
{
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   cout<<answer(arr)<<endl;
    return 0;
}
*/