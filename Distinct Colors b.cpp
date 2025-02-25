#include <bits/stdc++.h>
using namespace std;

int f(int node, int l, int r, int ql, int qr, int newVal, vector<int>& segTree) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && qr >= r) {
		if (newVal != -1) segTree[node] = newVal;
		return segTree[node];
	}
	int mid = (l+r)/2;
	int ans = f(2*node, l, mid, ql, qr, newVal, segTree) + f(2*node+1, mid+1, r, ql, qr, newVal, segTree);
	segTree[node] = segTree[2*node] + segTree[2*node+1];
	return ans;
}

void dfs(vector<vector<int>>& adj, vector<int>& col, int& cnt, unordered_map<int,int>& mp, vector<int>& segTree, vector<int>& ans, int node = 0, int par = 0) {
	if (mp.count(col[node])) f(1, 0, segTree.size()/2-1, mp[col[node]], mp[col[node]], 0, segTree);
	f(1, 0, segTree.size()/2-1, cnt, cnt, 1, segTree);
	mp[col[node]] = cnt;
	int in = cnt;
	for (int& neigh: adj[node]) if (neigh != par) dfs(adj, col, ++cnt, mp, segTree, ans, neigh, node);
	ans[node] = f(1, 0, segTree.size()/2-1, in, cnt, -1, segTree);
}

int main() {
	int n; cin>>n;
	vector<int> col(n);
	for (int& x: col) cin>>x;
	vector<vector<int>> adj(n);
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	unordered_map<int,int> mp;
	int newN = n; while (__builtin_popcount(newN) != 1) newN++;
	vector<int> segTree(2*newN);
	vector<int> ans(n);
	dfs(adj, col, cnt, mp, segTree, ans);
	for (int& x: ans) cout << x << ' ';
	return 0;
}

