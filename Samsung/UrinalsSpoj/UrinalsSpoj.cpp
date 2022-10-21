#include <bits/stdc++.h>
using namespace std;

struct UC {   // Urinal Chunk
	long long si;   // starting index
	long long ei;   // ending index
	long long dist; // distance

	bool operator<(UC const &uc) const {
		return dist < uc.dist;
	}
};

long long solve(long long n, long long k){
    if(k == 1)
        return 1;

    if(k > ceil(n/2)+1)
        return -1;

    if(k == 2)
        return n;

    string s(n, '-');
	s[0] = 'X';
	s[n-1] = 'X';

	priority_queue<UC> pq;
	pq.push({1, n-2, n-2-1+1});
	k -= 2;

	while(!pq.empty()){
		auto uc = pq.top();
		pq.pop();

		int mi = (uc.si + uc.ei) / 2;
		if(s[mi-1]=='X' || s[mi+1]=='X')
		    return -1;
		s[mi] = 'X';
		//cout<<s<<endl;

		if(--k == 0)
		    return mi+1;

		if(uc.si < mi)
			pq.push({uc.si, mi-1, mi-1-uc.si+1});
		if(uc.ei > mi)
			pq.push({mi+1, uc.ei, uc.ei-(mi+1)+1});
	}
	return -1;
}

int main() {
    int t;
    cin>>t;

    while(t--){
    	long long n, k;
    	cin>>n>>k;

    	long long ans = solve(n, k);
    	cout<<(ans == -1 ? "OOPS" : to_string(ans))<<endl<<endl;
	}
	return 0;
}