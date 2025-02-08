#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& inDegrees, vector<int>& outDegrees) {
	if (outDegrees[0] - inDegrees[0] != 1) return 0;
	if (inDegrees.back() - outDegrees.back() != 1) return 0;
	for (int i=1; i<inDegrees.size()-1; i++) if (inDegrees[i] != outDegrees[i]) return 0;
	return 1;
}

void dfs(int node, vector<vector<int>>& adj, vector<int>& ans) {
	while (adj[node].size()) {
		int neigh = adj[node].back();
		adj[node].pop_back();
		dfs(neigh, adj, ans);
	}
	ans.push_back(node);
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	vector<int> inDegrees(n), outDegrees(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		inDegrees[b-1]++;
		outDegrees[a-1]++;
	}
	if (!isPossible(inDegrees, outDegrees)) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<int> ans;
	dfs(0, adj, ans);
	if (ans.size() != m+1) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i=ans.size()-1; i>=0; i--) cout << ans[i]+1 << ' ';
	return 0;
}

