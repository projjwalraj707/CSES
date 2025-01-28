#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visLoc, vector<bool>& visGlobal, vector<int>& ans, bool& found) {
	ans.push_back(node);
	if (visLoc[node]) {
		found = 1;
		return;
	}
	visLoc[node] = 1;
	for (int neigh: adj[node]) {
		if (!found && !visGlobal[neigh]) dfs(neigh, adj, visLoc, visGlobal, ans, found);
	}
	visLoc[node] = 0;
	visGlobal[node] = 1;
	if (!found) {
		ans.pop_back();
	}
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		adj[a-1].push_back(b-1);
	}
	vector<int> ans;
	vector<bool> visLoc(n), visGlobal(n);
	bool found = 0;
	for (int i=0; i<n; i++) if (!visGlobal[i] && !found) dfs(i, adj, visLoc, visGlobal, ans, found);
	if (!found) cout << "IMPOSSIBLE";
	else {
		int i = 0; while (ans[i] != ans.back()) i++;
		cout << ans.size() - i << '\n';
		for (; i<ans.size(); i++) cout << ans[i] + 1 << ' ';
	}
	return 0;
}

