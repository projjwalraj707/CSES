#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findPar(int node, vector<int>& par) {
	if (par[node] == node) return node;
	return par[node] = findPar(par[node], par);
}

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
	if (vis[node]) return;
	vis[node] = 1;
	for (int& neigh: adj[node]) dfs(neigh, adj, vis);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin>>n>>m;
	vector<vector<int>> edges;
	vector<vector<int>> adj(n);
	for (int i=0, a, b, c; i<m; i++) {
		cin>>a>>b>>c;
		edges.push_back({c, a-1, b-1});
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	vector<bool> vis(n);
	dfs(0, adj, vis);
	if (accumulate(vis.begin(), vis.end(), 0) != n) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	sort(edges.begin(), edges.end());
	ll ans = 0;
	vector<int> par(n);
	for (int i=0; i<n; i++) par[i] = i;
	for (vector<int>& edge: edges) {
		if (findPar(edge[1], par) == findPar(edge[2], par)) continue;
		par[findPar(edge[2], par)] = findPar(edge[1], par);
		ans += edge[0];
	}
	cout << ans;
	return 0;
}
