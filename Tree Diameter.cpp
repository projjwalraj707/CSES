#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, int& ans, int node = 0, int par = -1) {
	int a = 0, b = 0;
	for (int& neigh: adj[node]) if (neigh != par) {
		int temp = dfs(adj, ans, neigh, node);
		if (temp >= a) {
			b = a;
			a = temp;
		}
		else if (temp > b) b = temp;
	}
	ans = max(ans, a+b+1);
	return max(a, b)+1;
}

int main() {
	int n; cin>>n;
	vector<vector<int>> adj(n);
	for (int i=0, a, b; i<n-1; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	dfs(adj, ans);
	cout << ans-1;
	return 0;
}

