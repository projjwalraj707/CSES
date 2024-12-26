#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
vector<ll> tree;

ll f(int currNode, int l, int r, int ql, int qr, int newVal = -1) {
	if (ql <= l && qr >= r) {
		if (newVal != -1) tree[currNode] = newVal;
		return tree[currNode];
	}
	if (ql > r || qr < l) return 0;
	int mid = (l+r)/2;
	ll sum = f(2*currNode, l, mid, ql, qr, newVal) + f(2*currNode+1, mid+1, r, ql, qr, newVal);
	tree[currNode] = tree[2*currNode] + tree[2*currNode+1];
	return sum;
}

int main() {
	int n, q;
	cin>>n>>q;
	vector<ll> arr(n);
	for (ll& x: arr) cin>>x;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(0);
	n = arr.size();
	tree.resize(2*n);
	for (int i=0; i<n; i++) tree[n+i] = arr[i];
	for (int i=n-1; i>0; i--) tree[i] = tree[2*i] + tree[2*i+1];
	while (q--) {
		int type; cin>>type;
		if (type == 1) {
			int k, u;
			cin>>k>>u;
			f(1, 0, n-1, k-1, k-1, u);
		}
		else {
			int a, b;
			cin>>a>>b;
			cout << f(1, 0, n-1, a-1, b-1) << nl;
		}
	}
	return 0;
}

