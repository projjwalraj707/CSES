#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXI = 1e17;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& doesChange, vector<bool>& vis) {
	if (vis[node]) return 0;
	vis[node] = 1;
	if (doesChange[node]) return 1;
	bool ans = 0;
	for (int neigh: adj[node]) ans = ans | dfs(neigh, adj, doesChange, vis);
	return ans;
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<ll>> edges(m, vector<ll>(3));
	vector<bool> doesChange(n);
	vector<vector<int>> revAdj(n);
	vector<bool> vis(n);
	for (ll i=0, a, b, c; i<m; i++) {
		cin>>a>>b>>c;
		edges[i] = {a-1, b-1, -c};
		revAdj[b-1].push_back(a-1);
	}
	vector<ll> ans(n, MAXI);
	ans[0] = 0;
	for (int i=0; i<n-1; i++)
		for (vector<ll>& e: edges) {
			ll a = e[0];
			ll b = e[1];
			ll c = e[2];
			if (ans[a] != MAXI && ans[b] > ans[a] + c)
				ans[b] = ans[a] + c;
		}
	for (vector<ll>& e: edges) {
		ll a = e[0];
		ll b = e[1];
		ll c = e[2];
		if (ans[a] != MAXI && ans[b] > ans[a] + c) {
			doesChange[b] = 1;
			ans[b] = ans[a] + c;
		}
	}
	bool temp = dfs(n-1, revAdj, doesChange, vis);
	if (temp) {
		cout << -1;
		return 0;
	}
	cout << -ans.back();
	return 0;
}
