#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans, bool& done) {
	if (vis[node]) {
		ans.push_back(node);
		return;
	}
	vis[node] = 1;
	for (int neigh: adj[node]) {
		if (!ans.size() && neigh != par) dfs(neigh, node, adj, vis, ans, done);
		if (ans.size()) break;
	}
	if (ans.size() && !done) {
		if (node == ans[0]) done = 1;
		ans.push_back(node);
	}
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	vector<int> vis(n);
	vector<int> ans;
	bool done = 0;
	for (int i=0; i<n; i++) if (!vis[i]) dfs(i, -1, adj, vis, ans, done);
	if (ans.size() == 0) cout << "IMPOSSIBLE" << "\n";
	else {
		cout << ans.size() << "\n";
		for (int i: ans) cout << i + 1 << ' ';

	}
	return 0;
}

