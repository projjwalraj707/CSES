//The only help I took was "Find answer for one of the nodes. Can the for its neighbours be concluded based the node's answer?"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<int>>& adj, ll& ans, vector<int>& cnt, int node = 0, int depth = 0, int par = -1) {
	ans += depth;
	cnt[node] = 1;
	for (int neigh: adj[node]) if (neigh != par) {
		dfs(adj, ans, cnt, neigh, depth+1, node);
		cnt[node] += cnt[neigh];
	}
}

void dfs2(vector<vector<int>>& adj, vector<ll>& ans, vector<int>& cnt, int node = 0, int par = -1) {
	for (int neigh: adj[node]) if (neigh != par) {
		ans[neigh] = ans[node] + adj.size() - 2*cnt[neigh];
		dfs2(adj, ans, cnt, neigh, node);
	}
}

int main() {
	int n; cin>>n;
	vector<vector<int>> adj(n);
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> cnt(n);
	vector<ll> ans(n);
	dfs(adj, ans[0], cnt);
	dfs2(adj, ans, cnt);
	for (ll& x: ans) cout << x << ' ';
	return 0;
}

