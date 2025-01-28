#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const ll MOD = 1e9+7;

int solve3(int& n, int& m, vector<ll>& dp, vector<vector<vector<int>>>& adj, vector<ll>& dist, int node) {
	if (node == 0) return 0;
	if (dp[node] != -1) return dp[node];
	int ans = 1e9;
	for (vector<int>& neigh: adj[node]) if (dist[node] == dist[neigh[0]] + neigh[1]) ans = min(ans, solve3(n, m, dp, adj, dist, neigh[0]) + 1);
	return dp[node] = ans;
}

int solve4(int& n, int& m, vector<ll>& dp,  vector<vector<vector<int>>>& adj, vector<ll>& dist, int node) {
	if (node == 0) return 0;
	if (dp[node] != -1) return dp[node];
	int ans = -1;
	for (vector<int>& neigh: adj[node]) if (dist[node] == dist[neigh[0]] + neigh[1]) ans = max(ans, solve4(n, m, dp, adj, dist, neigh[0]) + 1);
	return dp[node] = ans;
}

ll solve2(int& n, int& m, vector<ll>& dp, vector<vector<vector<int>>>& adj, vector<ll>& dist, int node) {
	if (node == 0) return 1;
	if (dp[node] != -1) return dp[node];
	ll ans = 0;
	for (vector<int>& neigh: adj[node]) if (dist[node] == dist[neigh[0]] + neigh[1]) ans = (ans + solve2(n, m, dp, adj, dist, neigh[0])) % MOD;
	return dp[node] = ans;
}

ll solve(int& n, int& m, vector<vector<vector<int>>>& adj, vector<ll>& dist) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minH;
	minH.push({0, 0});
	while (minH.size()) {
		ll currDist = minH.top().first, currNode = minH.top().second; minH.pop();
		if (currDist > dist[currNode]) continue;
		for (vector<int>& neigh: adj[currNode]) {
			if (dist[neigh[0]] > currDist + neigh[1]) {
				dist[neigh[0]] = currDist + neigh[1];
				minH.push({dist[neigh[0]], neigh[0]});
			}
		}
	}
	return dist.back();
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<vector<int>>> adj(n), revAdj(n);
	for (int i=0, a, b, c; i<m; i++) {
		cin>>a>>b>>c;
		adj[a-1].push_back({b-1, c});
		revAdj[b-1].push_back({a-1, c});
	}
	vector<ll> dist(n, INF);
	dist[0] = 0;
	cout << solve(n, m, adj, dist) << ' ';
	vector<ll> dp(n, -1);
	cout << solve2(n, m, dp, revAdj, dist, n-1) << ' ';
	dp = vector<ll> (n, -1);
	cout << solve3(n, m, dp, revAdj, dist, n-1) << ' ';
	dp = vector<ll> (n, -1);
	cout << solve4(n, m, dp, revAdj, dist, n-1) << ' ';
	return 0;
}

