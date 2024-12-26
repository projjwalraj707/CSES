#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ll long long

vector<int> tree;

int f(int node, int l, int r, int ql, int qr) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return tree[node];
	int mid = (l+r)/2;
	return f(2*node, l, mid, ql, qr) ^ f(2*node+1, mid+1, r, ql, qr);
}

int main() {
	int n, q; cin>>n>>q;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(0);
	n = arr.size();
	tree.resize(2*n);
	for (int i=0; i<n; i++) tree[i+n] = arr[i];
	for (int i=n-1; i>=1; i--) tree[i] = tree[2*i] ^ tree[2*i+1];
	while (q--) {
		int a, b; cin>>a>>b;
		cout << f(1, 0, n-1, a-1, b-1) << nl;
	}
	return 0;
}

