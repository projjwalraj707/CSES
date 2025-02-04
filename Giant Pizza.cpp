#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& vis, vector<int>& topo, vector<vector<int>>& adj) {
	if (vis[node]) return; 
	vis[node] = 1;
	for (int neigh: adj[node]) dfs(neigh, vis, topo, adj);
	topo.push_back(node);
}

void dfsSCC(int node, vector<vector<int>>& adj, vector<int>& SCC, int& curr) {
	if (SCC[node] != -1) return;
	SCC[node] = curr;
	for (int neigh: adj[node]) dfsSCC(neigh, adj, SCC, curr);
}

bool findSCC(vector<int>& SCC, vector<vector<int>>& adj, vector<vector<int>>& revAdj, int& n, int& m) {
	vector<bool> vis(2*m);
	vector<int> topo;
	for (int i=0; i<2*m; i++) if (!vis[i]) dfs(i, vis, topo, adj);
	int curr = 0;
	for (int i=2*m-1; i>=0; i--) if (SCC[topo[i]] == -1) dfsSCC(topo[i], revAdj, SCC, ++curr);
	for (int i=0; i<m; i++) if (SCC[i] == SCC[i+m]) return 0;
	return 1;
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(2*m), revAdj(2*m);
	for (int i=0,a,b; i<n; i++) {
		char x,y;
		cin>>x>>a>>y>>b; a--; b--;
		bool isFirstPos = (x == '+'), isSecondPos = (y == '+');
		adj[a+isFirstPos*m].push_back(b+(1-isSecondPos)*m);
		adj[b+isSecondPos*m].push_back(a+(1-isFirstPos)*m);
		revAdj[b+(1-isSecondPos)*m].push_back(a+isFirstPos*m);
		revAdj[a+(1-isFirstPos)*m].push_back(b+isSecondPos*m);
	}
	vector<int> SCC(2*m, -1);
	if (findSCC(SCC, adj, revAdj, n, m))
		for (int i=0; i<m; i++) if (SCC[i] > SCC[i+m]) cout << "+ "; else cout << "- ";
	else cout << "IMPOSSIBLE";
	return 0;
}

