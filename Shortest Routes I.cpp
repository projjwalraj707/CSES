#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dijkstra(int& n, int& m, vector<ll>& ans, vector<vector<pair<int,int>>>& adj) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minH;
	minH.push({0, 0});
	ans[0] = 0;
	while (minH.size()) {
		int currNode = minH.top().second;
		ll currDist = minH.top().first;
		minH.pop();
		if (ans[currNode] < currDist) continue;
		for (pair<int,int>& neigh: adj[currNode]) {
			if (ans[neigh.first] <= currDist + neigh.second) continue;
			ans[neigh.first] = ans[currNode] + neigh.second;
			minH.push({ans[neigh.first], neigh.first});
		}
	}
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n);
	for (int i=0, a, b, c; i<m; i++) {
		cin>>a>>b>>c;
		adj[a-1].push_back({b-1, c});
	}
	vector<ll> ans(n, 1e18);
	dijkstra(n, m, ans, adj);
	for (ll& i: ans) cout << i << ' ';
	return 0;
}

