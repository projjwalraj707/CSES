#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin>>n>>m;
	vector<int> inDegree(n);
	vector<vector<int>> adj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		inDegree[b-1]++;
		adj[a-1].push_back(b-1);
	}
	queue<int> q;
	for (int i=0; i<n; i++) if (inDegree[i] == 0) q.push(i);
	vector<int> ans;
	while (q.size()) {
		int top = q.front(); q.pop();
		ans.push_back(top);
		for (int neigh: adj[top]) {
			inDegree[neigh]--;
			if (inDegree[neigh] == 0) q.push(neigh);
		}
	}
	if (ans.size() != n) cout << "IMPOSSIBLE";
	else {
		for (int x: ans) cout << x + 1 << ' ';
	}
	return 0;
}


