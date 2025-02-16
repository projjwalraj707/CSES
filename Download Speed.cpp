#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bfs(ll& n, vector<unordered_map<ll, ll>>& adj, vector<ll>& par) {
	fill(par.begin(), par.end(), -1);
	queue<pair<ll, ll>> q;
	q.push({0, 1e18});
	while (q.size()) {
		ll node = q.front().first;
		ll mini = q.front().second;
		q.pop();
		if (node == n-1) return mini;
		for (pair<ll, ll> neigh: adj[node]) {
			if (par[neigh.first] != -1 || neigh.second <= 0) continue;
			q.push({neigh.first, min(neigh.second, mini)});
			par[neigh.first] = node;
		}
	}
	return 0;
}

int main() {
	ll n, m; cin>>n>>m;
	vector<unordered_map<ll, ll>> adj(n); //adj[node][neigh] = capacity
	for (ll i=0, a, b, c; i<m; i++) {
		cin>>a>>b>>c;
		a--; b--;
		adj[a][b] += c;
	}
	ll ans = 0;
	vector<ll> par(n);
	while (1)  {
		ll bottleneck = bfs(n, adj, par);
		if (bottleneck == 0) break;
		ans = ans + bottleneck;
		ll node = n-1;
		while (node != 0) {
			ll p = par[node];
			adj[p][node] -= bottleneck;
			adj[node][p] += bottleneck;
			node = par[node];
		}
	}
	cout << ans;
	return 0;
}

