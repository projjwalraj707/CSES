#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

vector<ll> treeLeft;
vector<ll> treeRight;

ll f(vector<ll>& tree, int node, int l, int r, int ql, int qr, ll newVal = LLONG_MAX) {
	if (ql > r || qr < l) return LLONG_MIN;
	if (ql <= l && qr >= r) {
		if (newVal != LLONG_MAX) tree[node] = newVal;
		return tree[node];
	}
	int mid = (l+r)/2;
	ll ans = max(f(tree, 2*node, l, mid, ql, qr, newVal), f(tree, 2*node+1, mid+1, r, ql, qr, newVal));
	tree[node] = max(tree[2*node], tree[2*node+1]);
	return ans;
}

int main() {
	int n, q; cin>>n>>q;
	vector<ll> arr(n);
	for (ll& x: arr) cin>>x;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(1e10);
	n = arr.size();

	//build the leftTree
	treeLeft.resize(2*n);
	for (int i=0; i<n; i++) treeLeft[n+i] = i - arr[i];
	for (int i=n-1; i>=1; i--) treeLeft[i] = max(treeLeft[2*i], treeLeft[2*i+1]);

	//build the treeRight
	treeRight.resize(2*n);
	for (int i=0; i<n; i++) treeRight[n+i] = -arr[i] - i;
	for (int i=n-1; i>=1; i--) treeRight[i] = max(treeRight[2*i], treeRight[2*i+1]);

	while (q--) {
		int type, k; cin>>type>>k;
		if (type == 1) {
			int x; cin>>x;
			f(treeLeft, 1, 0, n-1, k-1, k-1, k-1-x);
			f(treeRight, 1, 0, n-1, k-1, k-1, -x-k+1);
		}
		else {
			ll left = k-1-f(treeLeft, 1, 0, n-1, 0, k-1);
			ll right = -k+1-f(treeRight, 1, 0, n-1, k-1, n-1);
			cout << min(left, right) << nl;
		}
	}
	return 0;
}

