#include <bits/stdc++.h>
using namespace std;

int findPar(int node, vector<int>& par) {
	if (node == par[node]) return node;
	return par[node] = findPar(par[node], par);
}

void dfs(vector<vector<int>>& adj, int node, vector<int>& par) {
	for (int neigh: adj[node]) {
		if (findPar(node, par) == findPar(neigh, par)) continue;
		par[neigh] = findPar(node, par);
		dfs(adj, neigh, par);
	}
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	vector<int> par(n);
	for (int i=0; i<n; i++) par[i] = i;
	for (int i=0; i<n; i++) if (findPar(i, par) == i) dfs(adj, i, par);
	unordered_set<int> st;
	for (int i=0; i<n; i++) st.insert(findPar(i, par));
	cout << st.size()-1 << "\n";
	if (st.size() == 1) return 0;
	auto itr = st.begin(); itr++;
	while (itr != st.end()) {
		cout << *st.begin() + 1 << ' ' << *itr + 1 << "\n";
		itr++;
	}
	return 0;
}

