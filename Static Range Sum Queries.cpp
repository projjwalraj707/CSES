#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ll long long
vector<ll> tree;

ll f(ll root, ll l, ll r, ll ql, ll qr) {
	if (ql <= l && qr >= r) return tree[root];
	if (ql > r || qr < l) return 0;
	ll mid = (l+r)/2;
	return f(2*root, l, mid, ql, qr) + f(2*root+1, mid+1, r, ql, qr);
}

int main() {
	ll n, q; cin>>n>>q;
	vector<ll> arr(n);
	for (ll& i: arr) cin>>i;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(0); //make its size a power of 2

	n = arr.size();
	//build the tree
	tree.resize(2*n);
	for (ll i=0; i<n; i++) tree[n+i] = arr[i];
	for (ll i=n-1; i>=1; i--) tree[i] = tree[2*i] + tree[2*i+1];

	//proces the queries
	while (q--) {
		ll a, b; cin>>a>>b;
		cout << f(1, 0, arr.size()-1, a-1, b-1) << nl;
	}
	return 0;
}
