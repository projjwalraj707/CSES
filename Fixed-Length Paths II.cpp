//I konw it can be solved by applying range query over Fixed-Length Paths I solution but I cannot understand the O(1) solutioion available on the internet.
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int n, k1, k2, ans = 0;
vector<int> adj[MAXN];
int processed[MAXN]{0};
int subTreeSize[MAXN];
int cnt[MAXN];

int findCentroid(int& currN, int node, int par) {
	for (int& neigh: adj[node]) if (neigh != par && !processed[neigh] && subTreeSize[neigh] > currN/2) return findCentroid(currN, neigh, node);
	return node;
}

int calcSubTreeSize(int node, int par) {
	subTreeSize[node] = 1;
	for (int& neigh: adj[node]) if (neigh != par && !processed[neigh]) subTreeSize[node] += calcSubTreeSize(neigh, node);
	return subTreeSize[node];
}

void dfs(int node, int par, bool firstTime, int depth = 1) {
	
}

void solve(int node = 0) {
	calcSubTreeSize(node, node);
	int currN = subTreeSize[node]; //size of the current subTree
	node = findCentroid(currN, node, node);
	fill(cnt, cnt+k2+1, 0);
	for (int& neigh: adj[node]) if (!processed[neigh]) {
		dfs(neigh, neigh, 1);
		dfs(neigh, neigh, 0);
	}
}

int main() {
	cin>>n>>k1>>k2;
	for (int i=0,a,b; i<n-1; i++) {
		cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve();
	return 0;
}


