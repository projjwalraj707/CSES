#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& dp, vector<int>& sumDP, vector<vector<int>>& adj, int node, int par = -1) {
	if (dp[node] != -1) return dp[node];
	int bestSum = 0;
	for (int neigh: adj[node]) if (neigh != par) bestSum += solve(dp, sumDP, adj, neigh, node);
	int ans = bestSum;
	for (int neigh: adj[node]) if (neigh != par) ans = max(ans, bestSum - dp[neigh] + sumDP[neigh] + 1);
	dp[node] = ans;
	sumDP[node] = bestSum;
	return ans;
}

int main() {
	int n; cin>>n;
	vector<vector<int>> adj(n);
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> dp(n, -1), sumDP(n, -1);
	cout << solve(dp, sumDP, adj, 0);
	return 0;
}

