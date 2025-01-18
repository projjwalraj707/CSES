#include <bits/stdc++.h>
using namespace std;

bool isPossible(int startNode, vector<vector<int>>& adj, int& n, int& m, vector<int>& groups) {
	groups[startNode] = 0;
	queue<int> q;
	q.push(startNode);
	while (q.size()) {
		int currNode = q.front();
		q.pop();
		for (int neigh: adj[currNode]) {
			if (groups[neigh] == groups[currNode]) return 0;
			if (groups[neigh] == -1) {
				groups[neigh] = 1-groups[currNode];
				q.push(neigh);
			}
		}
	}
	return 1;
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	vector<int> groups(n, -1);
	bool ans = 1;
	for (int i=0; i<n; i++) if (groups[i] == -1) ans = ans && isPossible(i, adj, n, m, groups);
	if (ans) for (int& i: groups) cout << i + ((i == -1) ? 2 : 1) << ' ';
	else cout << "IMPOSSIBLE";
	return 0;
}

