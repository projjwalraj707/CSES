#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, vector<int>& subTreeSize, int node = 0, int par = 0) {
	for (int& neigh: adj[node]) if (neigh != par) subTreeSize[node] += dfs(adj,  subTreeSize, neigh, node);
	return subTreeSize[node];
}

int solve(vector<vector<int>>& adj, vector<int>& subTreeSize, int& n, int node = 0, int par = 0) {
	for (int& neigh: adj[node]) if (neigh != par) if (subTreeSize[neigh] > n/2) return solve(adj, subTreeSize, n, neigh, node);
	return node;
}

int main() {
	int n; cin>>n;
	vector<vector<int>> adj(n);
	vector<int> subTreeSize(n, 1);
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(adj, subTreeSize);
	cout << solve(adj, subTreeSize, n) + 1;
	return 0;
}

