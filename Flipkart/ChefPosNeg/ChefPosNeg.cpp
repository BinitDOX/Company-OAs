#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    unordered_set<int> s;
    int score = 0;
    for(int i = 0;i<n;i++){
        if(s.find(nums[i]) == s.end()){
            score+=abs(nums[i]);
            s.insert(nums[i]);
        } else {
            score-=abs(nums[i]);
        }
    }
    cout<<score<<endl;
}