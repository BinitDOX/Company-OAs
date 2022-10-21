#include <bits/stdc++.h>
using namespace std;

struct UC {   // Urinal Chunk
	int si;   // starting index
	int ei;   // ending index
	int dist; // distance

	bool operator<(UC const &uc) const {
		return dist < uc.dist;
	}
};

int main() {
	int n;
	cin>>n;

	string s(n, '-');
	priority_queue<UC> pq;

	pq.push({0, n-1, n-1-0+1});

	while(!pq.empty()){
		auto uc = pq.top();
		pq.pop();

		int mi = (uc.si + uc.ei) / 2;
		s[mi] = 'X';
		cout<<s<<endl;

		if(uc.si < mi)
			pq.push({uc.si, mi-1, mi-1-uc.si+1});
		if(uc.ei > mi)
			pq.push({mi+1, uc.ei, uc.ei-(mi+1)+1});
	}
}