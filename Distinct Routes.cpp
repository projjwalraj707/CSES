#include <bits/stdc++.h>
using namespace std;

int bfs(vector<unordered_map<int,int>>& adj, int& n, vector<int>& par) {
	fill(par.begin(), par.end(), -1);
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int node = q.front(); q.pop();
		if (node == n-1) break;
		for (pair<int,int> neigh: adj[node]) {
			if (neigh.second == 0 || par[neigh.first] != -1) continue;
			par[neigh.first] = node;
			q.push(neigh.first);
		}
	}
	if (par.back() == -1) return 0;
	int node = n-1;
	while (node != 0) {
		adj[par[node]][node] = 0;
		adj[node][par[node]] = 1;
		node = par[node];
	}
	return 1;
}

int dfs(int node, vector<int>& temp, vector<vector<int>>& orgAdj, vector<unordered_map<int,int>>& adj) {
	if (node == orgAdj.size()-1) return 1;
	for (int neigh: orgAdj[node]) {
		if (adj[node][neigh] == 0) {
			temp.push_back(neigh);
			adj[node][neigh] = 1;
			return dfs(neigh, temp, orgAdj, adj);
		}
	}
	return 0;
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> orgAdj(n);
	vector<unordered_map<int,int>> adj(n);
	for (int i=0,a,b; i<m; i++) {
		cin>>a>>b; a--; b--;
		orgAdj[a].push_back(b);
		adj[a][b] = 1;
	}
	vector<int> par(n);
	int bottleneck = 1;
	vector<vector<int>> ans;
	while (bottleneck) bottleneck = bfs(adj, n, par);
	bool cont = 1;
	while (cont) {
		vector<int> temp = {0};
		cont = dfs(0, temp, orgAdj, adj);
		if (cont) ans.push_back(temp);
	}
	cout << ans.size() << '\n';
	for (vector<int>& x: ans) {
		cout << x.size() << '\n';
		for (int y: x) cout << y + 1 << ' ';
		cout << '\n';
	}
	return 0;
}

