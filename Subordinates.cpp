#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int node, vector<int>& ans) {
	int temp = 1;
	for (int& neigh: adj[node]) {
		dfs(adj, neigh, ans);
		temp += ans[neigh];
	}
	ans[node] = temp;
}

int main() {
	int n; cin>>n;
	vector<vector<int>> adj(n);
	for (int i=1, a; i<n; i++) {
		cin>>a; a--;
		adj[a].push_back(i);
	}
	vector<int> ans(n, -1);
	dfs(adj, 0, ans);
	for (int& x: ans) cout << x-1 << ' ';
	return 0;
}

