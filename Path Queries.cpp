//took hint from: https://usaco.guide/CPH.pdf#page=174
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int& n, vector<vector<int>>& adj, vector<int>& in, vector<int>& out, vector<ll>& tree, vector<int>& val, int& id, int node = 0, int par = -1, ll sum = 0) {
	tree[n+id] = sum + val[node];
	in[node] = id;
	for (int& neigh: adj[node]) if (neigh != par) dfs(n, adj, in, out, tree, val, ++id, neigh, node, sum+val[node]);
	out[node] = id;
}

ll f(int node, int l, int r, int ql, int qr, int inc, vector<ll>& tree) {
	if (l > qr || r <  ql) return 0;
	if (l >= ql && r <= qr) {
		tree[node] += inc;
		return tree[node];
	}
	int mid = (l+r)/2;
	return tree[node] + f(2*node, l, mid, ql, qr, inc, tree) + f(2*node+1, mid+1, r, ql, qr, inc, tree);
}

int main() {
	int n, q; cin>>n>>q;
	vector<int> val(n) ;
	vector<vector<int>> adj(n);
	for (int& x: val) cin>>x;
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	while (__builtin_popcount(val.size()) != 1) val.push_back(0);
	n = val.size();
	vector<ll> tree(2*n);
	vector<int> in(n), out(n);
	int id = 0;
	dfs(n, adj, in, out, tree, val, id);
	while (q--) {
		int type, s, x; cin>>type>>s; s--;
		if (type == 1) {
			cin>>x;
			f(1, 0, n-1, in[s], out[s], x - val[s], tree);
			val[s] = x;
		}
		else cout << f(1, 0, n-1, in[s], in[s], 0, tree) << '\n';
	}
	return 0;
}

