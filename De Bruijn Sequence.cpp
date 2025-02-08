#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, string& ans) {
	while (adj[node].size()) {
		int neigh = adj[node].back();
		adj[node].pop_back();
		dfs(neigh, adj, ans);
	}
	if (node & 1) ans.push_back('1');
	else ans.push_back('0');
}

int main() {
	int n; cin>>n;
	if (n == 1) {
		cout << "10";
		return 0;
	}
	vector<vector<int>> adj((1<<(n-1)));
	for (int i=0; i<(1<<(n-1)); i++) {
		int neigh1 = i<<1;
		neigh1 = neigh1 ^ ((1<<(n-1)) & (neigh1));
		int neigh2 = (i<<1) ^ 1;
		neigh2 = neigh2 ^ ((1<<(n-1)) & (neigh2));
		adj[i].push_back(neigh1);
		adj[i].push_back(neigh2);
	}
	string ans;
	dfs(0, adj, ans);
	cout << ans << string(n-2, '0');
	return 0;
}

