#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin>>n>>m;
	vector<vector<vector<int>>> adj(n);
	for (int i=0,a,b,c; i<m; i++) {
		cin>>a>>b>>c;
		a--; b--;
		adj[a].push_back({b, c});
	}
	vector<int> dijkstra(n);
	dijkstra[0] = 1e9;
	priority_queue<pair<int,int>> maxH;
	maxH.push({1e9, 0});
	while (maxH.size()) {
		int currNode = maxH.top().second;
		int currMaxi = maxH.top().first;
		maxH.pop();
		if (dijkstra[currNode] > currMaxi) continue;
		for (vector<int>& neigh: adj[currNode]) {
			if (dijkstra[neigh[0]] < min(dijkstra[currNode], neigh[1])) {
				dijkstra[neigh[0]] = min(dijkstra[currNode], neigh[1]);
				maxH.push({dijkstra[neigh[0]], neigh[0]});
			}
		}
	}
	cout << dijkstra.back();
	return 0;
}

