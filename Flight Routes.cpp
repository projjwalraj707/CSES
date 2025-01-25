//NOT OMO; Copied from: https://usaco.guide/problems/cses-1196-flight-routes/solution
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, m, k; cin>>n>>m>>k;
	vector<vector<vector<int>>> adj(n);
	for (int i=0, a, b, c; i<m; i++) {
		cin>>a>>b>>c;
		adj[a-1].push_back({b-1, c});
	}
	vector<priority_queue<ll>> dist(n);
	dist[0].push(0);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minH;
	minH.push({0, 0});
	while (!minH.empty()) {
		auto top = minH.top();
		minH.pop();
		if (dist[top.second].top() < top.first) continue;
		for (vector<int>& neigh: adj[top.second]) {
			if (dist[neigh[0]].size() < k) {
				dist[neigh[0]].push(top.first + neigh[1]);
				minH.push({top.first+neigh[1], neigh[0]});
			}
			else if (dist[neigh[0]].top() > top.first + neigh[1]) {
				dist[neigh[0]].pop();
				dist[neigh[0]].push(top.first + neigh[1]);
				minH.push({top.first+neigh[1], neigh[0]});
			}
		}
	}
	vector<ll> ans;
	while (dist[n-1].size()) {
		ans.push_back(dist[n-1].top());
		dist[n-1].pop();
	}
	for (int i=ans.size()-1; i>=0; i--) cout << ans[i] << ' ';
	return 0;
}
