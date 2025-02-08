#include <bits/stdc++.h>
using namespace std;

void dfs2(int node, vector<vector<int>>& adj, vector<unordered_set<int>>& vis, vector<int>& ans) {
	while (adj[node].size()) {
		while (adj[node].size() && vis[node].count(adj[node].back())) adj[node].pop_back();
		if (!adj[node].size()) break;
		int neigh = adj[node].back();
		adj[node].pop_back();
		vis[node].insert(neigh);
		vis[neigh].insert(node);
		dfs2(neigh, adj, vis, ans);
	}
	ans.push_back(node+1);
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for (int i=0, a,b; i<m; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int oddDegreesCnt = 0;
	for (int i=0; i<n; i++) if (adj[i].size() % 2) oddDegreesCnt++;
	if (oddDegreesCnt != 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<unordered_set<int>> vis(n);
	vector<int> ans;
	dfs2(0, adj, vis, ans);
	if (ans.size() != m+1) { //can happen if the graph has more than one component
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int i: ans) cout << i << ' ';
	return 0;
}

