#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
	int n, m; cin>>n>>m;
	vector<vector<int>> edges;
	vector<vector<vector<int>>> adj(n);
	for (int i=0, a,b,c; i<m; i++) {
		cin>>a>>b>>c;
		edges.push_back({a-1, b-1, c});
		adj[a-1].push_back({b-1, c});
	}
	vector<ll> dist(n);
	vector<int> par(n);
	for (int i=0; i<n-1; i++) for (vector<int>& edge: edges) {
		int a = edge[0], b = edge[1], c = edge[2];
		if (dist[b] > dist[a] + c) {
			dist[b] = dist[a] + c;
			par[b] = a;
		}
	}
	for (vector<int>& edge: edges) {
		int a = edge[0], b = edge[1], c = edge[2];
		if (dist[b] > dist[a] + c) {
			int node = a;
			vector<bool> vis(n);
			vector<int> ans;
			while (!vis[node]) {
				vis[node] = 1;
				ans.push_back(node);
				node = par[node];
			}
			cout << "YES" << '\n';
			cout << node+1 << ' ';
			while (ans.back() != node) {
				cout << ans.back() + 1 << ' ';
				ans.pop_back();
			}
			cout << node+1;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
