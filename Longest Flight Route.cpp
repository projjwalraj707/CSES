#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	vector<vector<int>> revAdj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		revAdj[b-1].push_back(a-1);
		adj[a-1].push_back(b-1);
	}
	vector<int> dist(n, -1);
	priority_queue<pair<int,int>> q;
	q.push({0, n-1});
	while (q.size()) {
		auto top = q.top();
		q.pop();
		if (dist[top.second] > top.first) continue;
		for (int neigh: revAdj[top.second]) {
			if (dist[neigh] < top.first + 1) {
				dist[neigh] = top.first + 1;
				q.push({dist[neigh], neigh});
			}
		}
	}
	if (dist[0] == -1) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	int node = 0;
	cout << dist[0] + 1 << '\n';
	cout << 1 << ' ';
	while (dist[node] != 1) {
		int currDist = 0;
		for (int neigh: adj[node]) currDist = max(currDist, dist[neigh]);
		for (int neigh: adj[node]) if (dist[neigh] == currDist) {
			cout << neigh + 1 << ' ';
			dist[node] = -1;
			node = neigh;
			break;
		}

	}
	cout << n;
	return 0;
}
