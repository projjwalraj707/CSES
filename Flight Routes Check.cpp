#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, bool& isNormal, vector<bool>& vis) {
	if (vis[node] == isNormal) return;
	vis[node] = isNormal;
	for (int neigh: adj[node]) dfs(neigh, adj, isNormal, vis);
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n), revAdj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		revAdj[b].push_back(a);
	}
	vector<bool> vis(n);
	bool isNormal = 1;
	dfs(0, adj, isNormal, vis);
	for (int i=0; i<n; i++) if (!vis[i]) {
		cout << "NO" << '\n'; 
		cout << 1 << ' ' << i+1;
		return 0;
	}
	isNormal = 0;
	dfs(0, revAdj, isNormal, vis);
	for (int i=0; i<n; i++) if (vis[i]) {
		cout << "NO" << '\n';
		cout << i+1 << ' ' << 1;
		return 0;
	}
	cout << "YES";
	return 0;
}

