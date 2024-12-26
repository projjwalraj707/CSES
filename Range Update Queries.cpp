#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

vector<ll> tree;

ll f(int node, int l, int r, int ql, int qr, int inc = 0) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) {
		tree[node] += inc;
		return tree[node];
	}
	int mid = (l+r)/2;
	return tree[node] + f(2*node, l, mid, ql, qr, inc) + f(2*node+1, mid+1, r, ql, qr, inc);
}

int main() {
	int n, q;
	cin>>n>>q;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(0);
	n = arr.size();
	tree.resize(2*n);
	for (int i=0; i<n; i++) tree[n+i] = arr[i];
	//for (int i=n-1; i>=1; i--) tree[i] = tree[2*i] + tree[2*i+1];
	while (q--) {
		int type; cin>>type;
		if (type == 1) {
			int a, b, u; cin>>a>>b>>u;
			f(1, 0, n-1, a-1, b-1, u);
		}
		else {
			int k; cin>>k;
			cout << f(1, 0, n-1, k-1, k-1) << nl;
		}
	}
	return 0;
}

