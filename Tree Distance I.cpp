//Solution 2: https://usaco.guide/problems/cses-1132-tree-distances-i/solution
#include <bits/stdc++.h>
using namespace std;

void findFarthestNode(vector<vector<int>>& adj, int& ans, int& maxi, int node, int par = -1, int depth = 0) {
	if (adj[node].size() == 1 && adj[node][0] == par) {
		if (depth > maxi) {
			maxi = depth;
			ans = node;
		}
		return;
	}
	for (int& neigh: adj[node]) if (neigh != par)
		findFarthestNode(adj, ans, maxi, neigh, node, depth+1);
}

void dfs(vector<vector<int>>& adj, int node, vector<int>& dist, int depth = 0, int par = -1) {
	dist[node] = depth;
	for (int neigh: adj[node]) if (neigh != par) dfs(adj, neigh, dist, depth+1, node);
}

int main() {
	int n; cin>>n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	vector<vector<int>> adj(n);
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int a, b, maxi = 0;
	findFarthestNode(adj, a, maxi, 0);
	maxi = 0;
	findFarthestNode(adj, b, maxi, a);
	vector<int> dist1(n), dist2(n);
	dfs(adj, a, dist1);
	dfs(adj, b, dist2);
	for (int i=0; i<n; i++) cout << max(dist1[i], dist2[i]) << ' ';
	return 0;
}


