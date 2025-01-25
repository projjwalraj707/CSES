#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

void Dijkstra(int& n, int& m, vector<vector<vector<int>>>& adj, vector<ll>& minDist, int source) {
	minDist[source] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minH;
	minH.push({0, source});
	while (minH.size()) {
		int currNode = minH.top().second;
		ll currDist = minH.top().first;
		minH.pop();
		if (minDist[currNode] < currDist) continue;
		for (vector<int>& neigh: adj[currNode]) {
			if (minDist[neigh[0]] > minDist[currNode] + neigh[1]) {
				minDist[neigh[0]] = minDist[currNode] + neigh[1];
				minH.push({minDist[neigh[0]], neigh[0]});
			}
		}
	}
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<vector<int>>> flights(n);
	vector<vector<vector<int>>> flightsRev(n);
	vector<vector<int>> edges;
	for (int i=0, a, b, c; i<m; i++) {
		cin>>a>>b>>c;
		flights[a-1].push_back({b-1, c});
		flightsRev[b-1].push_back({a-1, c});
		edges.push_back({a-1, b-1, c});
	}
	vector<ll> minDistFrom0(n, 1e18), minDistFromN(n, 1e18);
	Dijkstra(n, m, flights, minDistFrom0, 0);
	Dijkstra(n, m, flightsRev, minDistFromN, n-1);
	ll ans = minDistFrom0.back();
	for (vector<int>& edge: edges) {
		int a = edge[0], b = edge[1];
		ll c = edge[2];
		if (minDistFrom0[a] != INF && minDistFromN[b] != INF) ans = min(ans, minDistFrom0[a] + minDistFromN[b] + c/2);
	}
	cout << ans;
	return 0;
}


