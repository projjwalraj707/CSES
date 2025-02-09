#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll solve(int node, int& n, vector<vector<int>>& adj, vector<vector<ll>>& dp, int mask = 1) {
	if (mask == ((1<<n)-1))
		if (node == n-1) return 1;
		else return 0;
	if (node == n-1) return 0; //saw this optimization online
	if (dp[node][mask] != -1) return dp[node][mask];
	ll ans = 0;
	for (int neigh: adj[node]) if ((mask & (1<<neigh)) == 0) ans = (ans + solve(neigh, n, adj, dp, mask ^ (1<<neigh))) % MOD;
	return dp[node][mask] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for (int i=0,a,b; i<m; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
	}
	vector<vector<ll>> dp(n, vector<ll>(1<<n, -1));
	cout << solve(0, n, adj, dp);
	return 0;
}

