#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<unordered_map<int,int>>& adj, unordered_set<int>& A) {
	for (pair<int,int> neigh: adj[node]) {
		if (neigh.second == 0 || A.count(neigh.first)) continue;
		A.insert(neigh.first);
		dfs(neigh.first, adj, A);
	}
}

int bfs(vector<unordered_map<int,int>>& adj) {
	queue<int> q;
	q.push(0);
	vector<int> par(adj.size(), -1);
	while (q.size()) {
		int node = q.front(); q.pop();
		if (node == adj.size()-1) break;
		for (pair<int,int> neigh: adj[node]) {
			if (par[neigh.first] != -1 || neigh.second == 0) continue;
			q.push(neigh.first);
			par[neigh.first] = node;
		}
	}
	if (par.back() == -1) return 0;
	int node = adj.size()-1;
	while (node != 0) {
		adj[par[node]][node] = 0;
		adj[node][par[node]] = 1;
		node = par[node];
	}
	return 1;
}

int main() {
	int n, m; cin>>n>>m;
	vector<unordered_map<int,int>> adj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	int bottleneck = 1;
	while (bottleneck) bottleneck = bfs(adj);
	unordered_set<int> A;
	A.insert(0);
	dfs(0, adj, A);
	vector<vector<int>> ans;
	for (int a: A) {
		for (pair<int,int> neigh: adj[a]) {
			if (neigh.second == 0 && !A.count(neigh.first)) ans.push_back({a, neigh.first});
		}
	}
	cout << ans.size() << '\n';
	for (vector<int>& x: ans) cout << x[0] + 1 << ' ' << x[1] + 1 << '\n';
	return 0;
}
