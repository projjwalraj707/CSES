#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define nl "\n"

vector<int> tree;

int f(int node, int l, int r, int dec) {
	if (l == r) {
		tree[node] -= dec;
		return l + 1;
	}
	int mid = (l+r)/2;
	int ans;
	if (tree[2*node] >= dec) ans =  f(2*node, l, mid, dec);
	else ans = f(2*node+1, mid+1, r, dec);
	tree[node] = max(tree[2*node], tree[2*node+1]);
	return ans;
}

int main() {
	int n, m; cin>>n>>m;
	vector<int> rooms(n);
	for (int &x: rooms) cin>> x;
	while (__builtin_popcount(rooms.size()) != 1) rooms.push_back(0);
	n = rooms.size();
	tree.resize(2*n);
	for (int i=0; i<n; i++) tree[n+i] = rooms[i];
	for (int i=n-1; i>=1; i--) tree[i] = max(tree[2*i], tree[2*i+1]);

	while (m--) {
		int r; cin>>r;
		if (r > tree[1]) cout << 0;
		else cout << f(1, 0, n-1, r);
		cout<<" ";
	}
	return 0;
}

