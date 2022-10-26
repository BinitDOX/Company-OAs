#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<int> tree;
    vector<int> arr;

    int buildTree(int si, int ei, int ti){
        if(si == ei)
            return tree[ti] = arr[si];

        int mi = (si + ei) / 2;
        int left = buildTree(si, mi, 2*ti+1);
        int right = buildTree(mi+1, ei, 2*ti+2);
        return tree[ti] = max(left, right);
    }

    int rangeMax(int qsi, int qei, int si, int ei, int ti){
        if(si >= qsi && ei <= qei)
            return tree[ti];
        if(si > qei || ei < qsi)
            return 0;

        int mi = (si + ei) / 2;
        int left = rangeMax(qsi, qei, si, mi, 2*ti+1);
        int right = rangeMax(qsi, qei, mi+1, ei, 2*ti+2);
        return max(left, right);
    }

    void update(int qi, int si, int ei, int ti, int diff){
        if(si > qi || ei < qi)
            return;

        tree[ti] += diff;

        if(si == ei)
            return;

        int mi = (si + ei) / 2;
        update(qi, si, mi, 2*ti+1, diff);
        update(qi, mi+1, ei, 2*ti+2, diff);
    }

public:
    SegmentTree(){}

    SegmentTree(vector<int> &arr){
        this->arr = arr;
        int n = arr.size();
        tree.resize(1<<(int)(ceil(log2(n))+1));

        buildTree(0, n-1, 0);
    }

    void displayTree(){
        for(int i=0; i<tree.size(); i++)
            cout<<tree[i]<<" ";
        cout<<endl;
    }

    int rangeMax(int qsi, int qei){
        return rangeMax(qsi, qei, 0, arr.size()-1, 0);
    }

    void update(int qi, int val){
        int diff = val - arr[qi];
        arr[qi] += diff;
        update(qi, 0, arr.size()-1, 0, diff);
    }
};


struct Laptop {
    int price;
    int rating;
};

void buyLaptopSolve(vector<Laptop> &laptop, int n, vector<pair<int, int>> &query){
    sort(laptop.begin(), laptop.end(), [](Laptop &a, Laptop &b){
        return a.price < b.price;
    });  

    map<int, int> indexmap;
    for(int i=0; i<n; i++)
        indexmap[laptop[i].price] = i;
    
    vector<int> ratings(n);
    for(int i=0; i<n; i++)
        ratings[i] = laptop[i].rating;
    
    SegmentTree st(ratings);

    for(auto q : query){
        auto lb = indexmap.lower_bound(q.first);
        auto ub = indexmap.upper_bound(q.second);
        ub--;
        
        cout<<st.rangeMax(lb->second, ub->second)<<endl;
    }
}

int main(){
    int n;
    cin>>n;

    vector<Laptop> laptop(n);

    for(int i=0; i<n; i++)
        cin>>laptop[i].price>>laptop[i].rating;

    int q;
    cin>>q;

    vector<pair<int, int>> query(q);
    for(int i=0; i<q; i++)
        cin>>query[i].first>>query[i].second;

    buyLaptopSolve(laptop, n, query);

    return 0; 
}

