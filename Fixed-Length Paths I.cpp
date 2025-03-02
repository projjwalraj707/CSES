#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5+1;
ll ans = 0;
vector<int> adj[MAXN];
int processed[MAXN]{0};
int subTreeSize[MAXN]{0};
ll cnt[MAXN]{1};
int max_depth;

int calcSubTreeSize(int node, int par) {
	subTreeSize[node] = 1;
	for (int& neigh: adj[node]) if (neigh != par && !processed[neigh]) subTreeSize[node] += calcSubTreeSize(neigh, node);
	return subTreeSize[node];
}

int findCentroid(int& n, int node, int par) {
	for (int& neigh: adj[node]) if (neigh != par && !processed[neigh] && subTreeSize[neigh] > n/2) return findCentroid(n, neigh, node);
	return node;
}

void dfs(int& k, int node, int par, bool firstTime, int depth = 1) {
	if (depth > k) return;
	max_depth = max(max_depth, depth);
	if (firstTime) ans += cnt[k-depth];
	else cnt[depth]++;
	for (int& neigh: adj[node]) if (neigh != par && !processed[neigh])
		dfs(k, neigh, node, firstTime, depth+1);
}

void solve(int& k, int node = 0) {
	calcSubTreeSize(node, node);
	int n = subTreeSize[node]; //size of the current subTree
	node = findCentroid(n, node, node);
	processed[node] = 1;
	max_depth = 0;
	for (int& neigh: adj[node]) if (!processed[neigh]) {
		dfs(k, neigh, neigh, 1);
		dfs(k, neigh, neigh, 0);
	}
	fill(cnt+1, cnt+max_depth+1, 0); //this max_depth this was copied from usaco else mostly done by me
	for (int& neigh: adj[node]) if (!processed[neigh])
		solve(k, neigh);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin>>n>>k;
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve(k);
	cout << ans;
	return 0;
}

