#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& dist, vector<vector<int>>& hier, int node = 0, int par = -1, int depth = 0) {
	dist[node] = depth;
	hier[node][0] = par;
	for (int neigh: adj[node]) if (neigh != par) dfs(adj, dist, hier, neigh, node, depth+1);
}

int findPar(int node, int k, vector<vector<int>>& hier) {
	if (k == 0) return node;
	for (int i=0; (1<<i) <= k; i++) {
		if ((1<<i) & k) node = hier[node][i];
	}
	return node;
}

int LCA(int a, int b, vector<vector<int>>& hier, vector<int>& dist) {
	if (dist[b] < dist[a]) swap(a, b);
	b = findPar(b, dist[b]-dist[a], hier);
	if (a == b) return a;
	for (int i=17; i>=0; i--) {
		if (hier[a][i] == hier[b][i]) continue;
		a = hier[a][i];
		b = hier[b][i];
	}
	return hier[a][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,q; cin>>n>>q;
	vector<vector<int>> adj(n);
	vector<vector<int>> hier(n, vector<int>(18, -1));
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> dist(n);
	dfs(adj, dist, hier);
	for (int j=1; j<18; j++) for (int i=1; i<n; i++) if (hier[i][j-1] != -1) hier[i][j] = hier[hier[i][j-1]][j-1];
	while (q--) {
		int a, b; cin>>a>>b; a--; b--;
		int c = LCA(a, b, hier, dist);
		cout << dist[a] + dist[b] - 2*dist[c] << '\n';
	}
	return 0;
}
