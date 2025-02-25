#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<unordered_set<int>>& st, vector<int>& col, vector<int>& ans, int node = 0, int par = -1) {
	int maxi = -1;
	for (int i=0; i<adj[node].size(); i++) if (adj[node][i] != par) {
		dfs(adj, st, col, ans, adj[node][i], node);
		if (maxi == -1 || st[adj[node][maxi]].size() < st[adj[node][i]].size()) maxi = i;
	}
	if (maxi == -1) {
		st[node].insert(col[node]);
		ans[node] = 1;
		return;
	}
	swap(st[node], st[adj[node][maxi]]);
	st[node].insert(col[node]);
	for (int i=0; i<adj[node].size(); i++) if (adj[node][i] != par && i != maxi) 
		for (int x: st[adj[node][i]]) st[node].insert(x);
	ans[node] = st[node].size();
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
	vector<unordered_set<int>> st(n);
	vector<int> ans(n);
	dfs(adj, st, col, ans);
	for (int& x: ans) cout << x << ' ';
	return 0;
}

