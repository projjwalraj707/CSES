#include <bits/stdc++.h>
using namespace std;

int findKthPar(int node, int k, vector<vector<int>>& hier) {
	if (k == 0) return node;
	for (int i=0; (1<<i) <= k; i++) if ((1<<i) & k) node = hier[node][i];
	return node;
}

int LCA(int node1, int node2, vector<vector<int>>& hier, vector<int>& dist) {
	if (dist[node1] > dist[node2]) swap(node1, node2);
	node2 = findKthPar(node2, dist[node2]-dist[node1], hier);
	if (node1 == node2) return node1;
	for (int i=17; i>=0; i--) {
		if (hier[node1][i] == hier[node2][i]) continue;
		node1 = hier[node1][i];
		node2 = hier[node2][i];
	}
	return hier[node1][0];
}

void dfs(vector<vector<int>>& hier, vector<vector<int>>& adj, vector<int>& dist, int node = 0, int par = 0, int depth = 0) {
	hier[node][0] = par;
	dist[node] = depth;
	for (int& neigh: adj[node]) if (neigh != par) dfs(hier, adj, dist, neigh, node, depth+1);
}

int dfs2(vector<vector<int>>& adj, vector<int>& pref, int node = 0, int par = -1) {
	for (int& neigh: adj[node]) if (neigh != par) pref[node] += dfs2(adj, pref, neigh, node);
	return pref[node];
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	vector<vector<int>> hier(n, vector<int>(18));
	vector<int> dist(n);
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(hier, adj, dist);
	for (int i=1; i<18; i++) for (int j=1; j<n; j++) hier[j][i] = hier[hier[j][i-1]][i-1];
	vector<int> pref(n);
	for (int i=0,a,b; i<m; i++) {
		cin>>a>>b; a--; b--;
		int c = LCA(a, b, hier, dist);
		pref[a]++;
		pref[b]++;
		pref[c]--;
		if (c != 0) pref[hier[c][0]]--;
	}
	dfs2(adj, pref);
	for (int i: pref) cout << i << ' ';
	return 0;
}


