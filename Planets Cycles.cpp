#include <bits/stdc++.h>
using namespace std;

int findKthChild(int node, const int& k, vector<vector<int>>& child, vector<int>& t) {
	int ind = 0;
	while ((1<<ind) <= k) {
		if (k & (1<<ind)) node = child[node][ind];
		ind++;
	}
	return node;
}

void dfs(int node, vector<int>& t, vector<int>& isPartOfCircle, vector<bool>& vis, vector<int>& dist, bool& insideCircle, int depth = 0) {
	if (isPartOfCircle[node] != -1) return;
	if (vis[node]) {
		insideCircle = 1;
		dist[node] = depth - dist[node];
		isPartOfCircle[node] = 1;
		return;
	}
	dist[node] = depth;
	vis[node] = 1;
	dfs(t[node]-1, t, isPartOfCircle, vis, dist, insideCircle, depth+1);
	if (isPartOfCircle[node] == 1) {
		insideCircle = 0;
		dist[node] = dist[t[node]-1];
		insideCircle = 0;
	}
	else if (insideCircle == 0) {
		isPartOfCircle[node] = 0;
		if (isPartOfCircle[t[node]-1]) dist[node] = 1;
		else dist[node] = dist[t[node]-1]+1;
	}
	else {
		isPartOfCircle[node] = 1;
		dist[node] = dist[t[node]-1];
	}
}

int main() {
	int n; cin>>n;
	vector<int> t(n);
	for (int& x: t) cin>>x;
	vector<int> isPartOfCircle(n, -1), //0: not a part of circle, 1: part of circle; alsos
		dist(n, -1); //if (isPartOfCircle[i] == 1) dist[i] == circle size else dist[i] = distance from circle
	vector<bool> vis(n);
	bool insideCircle = 0;
	for (int i=0; i<n; i++) if (!vis[i]) dfs(i, t, isPartOfCircle, vis, dist, insideCircle);
	vector<vector<int>> child(n, vector<int>(18));
	for (int i=0; i<n; i++) child[i][0] = t[i]-1;
	for (int j=1; j<18; j++) for (int i=0; i<n; i++) child[i][j] = child[child[i][j-1]][j-1];
	for (int i=0; i<n; i++) {
		if (isPartOfCircle[i]) cout << dist[i] << ' ';
		else cout << dist[findKthChild(i, dist[i], child, t)] + dist[i] << ' ';
	}
	return 0;
}

