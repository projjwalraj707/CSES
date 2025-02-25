#include <bits/stdc++.h>
using namespace std;

int ans = -1;
void dfs(vector<vector<int>>& adj, vector<int>& subTreeSize, int node = 0, int par = 0) {
	int maxi = 0;
	int sum = 0;
	for (int& neigh: adj[node]) if (neigh != par) {
		dfs(adj, subTreeSize, neigh, node);
		subTreeSize[node] += subTreeSize[neigh];
		maxi = max(maxi, subTreeSize[neigh]);
		sum += subTreeSize[neigh];
	}
	maxi = max(maxi, (int)subTreeSize.size() - sum - 1);
	if (maxi <= subTreeSize.size()/2) ans = node+1;
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
	cout << ans;
	return 0;
}
