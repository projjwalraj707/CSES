//Kosaraju algorithm
#include <bits/stdc++.h>
using namespace std;

void dfsTopo(int node, vector<vector<int>>& adj, vector<int>& topo, vector<bool>& vis) {
	if (vis[node]) return;
	vis[node] = 1;
	for (int& neigh: adj[node]) dfsTopo(neigh, adj, topo, vis);
	topo.push_back(node);
}

void dfs(int node, vector<vector<int>>& adj, int& currKingdom, vector<int>& ans) {
	if (ans[node] != 0) return;
	ans[node] = currKingdom;
	for (int neigh: adj[node]) dfs(neigh, adj, currKingdom, ans);
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n), revAdj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		revAdj[b].push_back(a);
	}
	vector<bool> vis(n);
	vector<int> topo;
	for (int i=0; i<n; i++) if (!vis[i]) dfsTopo(i, adj, topo, vis);
	vector<int> ans(n);
	int curr = 1;
	for (int i=n-1; i>=0; i--) {
		if (ans[topo[i]] == 0) {
			dfs(topo[i], revAdj, curr, ans);
			curr++;
		}
	}
	cout << curr-1 << '\n';
	for (int& x: ans) cout << x << ' ';
	return 0;
}

