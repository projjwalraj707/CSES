#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

ll solve(vector<vector<int>>& adj, int node, vector<ll>& dp) {
	if (node == adj.size()-1) return 1;
	if (dp[node] != -1) return dp[node];
	ll ans = 0;
	for (int neigh: adj[node]) ans = (ans + solve(adj, neigh, dp)) % MOD;
	return dp[node] = ans;
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		adj[a-1].push_back(b-1);
	}
	vector<ll> dp(n, -1);
	cout << solve(adj, 0, dp);
	return 0;
}

