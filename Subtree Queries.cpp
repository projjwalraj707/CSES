#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int& n, vector<vector<int>>& adj, vector<int>& in, vector<int>& out, int& path, vector<ll>& tree, vector<int>& val, int node = 0, int par = -1) {
	in[node] = path;
	tree[n+path] = val[node];
	for (int& neigh: adj[node]) if (neigh != par) dfs(n, adj, in, out, ++path, tree, val, neigh, node);
	out[node] = path;
}

ll f(int node, int l, int r, int ql, int qr, int newVal, vector<ll>& tree) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && qr >= r) {
		if (newVal != -1) tree[node] = newVal; //will only be triggered for leaf nodes
		return tree[node];
	}
	int mid = (l+r)/2;
	ll ans = f(2*node, l, mid, ql, qr, newVal, tree) + f(2*node+1, mid+1, r, ql, qr, newVal, tree);
	tree[node] = tree[2*node] + tree[2*node+1];
	return ans;
}

int main() {
	int n, q; cin>>n>>q;
	vector<int> val(n);
	vector<vector<int>> adj(n);
	for (int& x: val) cin>>x;
	for (int i=0, a, b; i<n-1; i++) {
		cin>>a>>b;  a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	while (__builtin_popcount(val.size()) != 1) val.push_back(0);
	n = val.size();
	vector<ll> tree(2*n);
	vector<int> in(n), out(n);
	int path = 0;
	dfs(n, adj, in, out, path, tree, val);
	for (int i=n-1; i>=1; i--) tree[i] = tree[2*i] + tree[2*i+1];
	/*
	for (int& x: in) cout << x << ' '; cout << endl;
	for (int& x: out) cout << x << ' '; cout << endl;
	for (ll& x: tree) cout << x << ' '; cout << endl;
	return 0;
	*/

	while (q--) {
		int type, s, x; cin>>type>>s; s--;
		if (type == 1) {
			cin>>x;
			f(1, 0, n-1, in[s], in[s], x, tree);
		}
		else cout << f(1, 0, n-1, in[s], out[s], -1, tree) << '\n';
	}
	return 0;
}

