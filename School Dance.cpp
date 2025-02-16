//took help from CSES book
#include<bits/stdc++.h>
using namespace std;

int bfs(vector<unordered_map<int,int>>& adj, int& n, int& m) {
	vector<int> par(n+m+2, -1);
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int node = q.front(); q.pop();
		if (node == n+m+1) break;
		for (pair<int,int> neigh: adj[node]) {
			if (neigh.second == 0 || par[neigh.first] != -1) continue;
			par[neigh.first] = node;
			q.push(neigh.first);
		}
	}
	if (par.back() == -1) return 0;
	int node = n+m+1;
	while (node != 0) {
		adj[par[node]][node] = 0;
		adj[node][par[node]] = 1;
		node = par[node];
	}
	return 1;
}

void dfs(vector<unordered_map<int,int>>& adj, int node, unordered_set<int>& A) {
	for (pair<int,int> neigh: adj[node]) {
		if (neigh.second != 0 || A.count(neigh.first)) continue;
		A.insert(node);
		dfs(adj, neigh.first, A);
	}
}

int main() {
	int n, m, k; cin>>n>>m>>k;
	vector<unordered_map<int,int>> adj(n+m+2);
	for (int i=0, a, b; i<k; i++) {
		cin>>a>>b;
		adj[a][b+n] = 1;
	}
	for (int i=0; i<n; i++) adj[0][i+1] = 1;
	for (int i=0; i<m; i++) adj[i+n+1][n+m+1] = 1;
	int bottleneck = 1;
	while (bottleneck) bottleneck = bfs(adj, n, m);
	unordered_set<int> A;
	A.insert(0);
	dfs(adj, 0, A);
	vector<vector<int>> ans;
	for (int i=1; i<=n; i++) for (pair<int,int> neigh: adj[i]) if (adj[i][neigh.first] == 0) ans.push_back({i, neigh.first});
	cout << ans.size() << '\n';
	for (vector<int>& x: ans) cout << x[0] << ' ' << x[1] - n << '\n';
	return 0;
}

