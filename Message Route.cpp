#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& dist, vector<vector<int>>& adj) {
	cout << node + 1<< " ";
	if (node == adj.size()-1) return;
	int mini = 1e9;
	for (int neigh: adj[node]) mini = min(mini, dist[neigh]);
	for (int neigh: adj[node]) if (dist[neigh] == mini) {
		dfs(neigh, dist, adj);
		return;
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
	vector<int> dist(n, 1e9);
	dist[n-1] = 0;
	queue<pair<int,int>> q;
	q.push({n-1, 0});
	while (q.size() && dist[0] == 1e9) {
		int node = q.front().first, currDist = q.front().second; q.pop();
		for (int neigh: adj[node]) {
			if (dist[neigh] < 1e9) continue;
			dist[neigh] = currDist+1;
			q.push({neigh, currDist+1});
		}
	}
	if (dist[0] == 1e9) cout << "IMPOSSIBLE";
	else {
		cout << dist[0] + 1 << "\n";
		dfs(0, dist, adj);
	}
	return 0;
}

