#include <bits/stdc++.h>
using namespace std;

void findDistTree(int node, vector<int>& t, vector<int>& isPartOfCircle, vector<int>& dist) {
	if (dist[node] != -1) return;
	if (isPartOfCircle[t[node]-1]) {
		dist[node] = 1;
		return;
	}
	findDistTree(t[node]-1, t, isPartOfCircle, dist);
	dist[node] = dist[t[node]-1]+1;
}

void findDistCircle(int node, vector<int>& t, vector<int>& isPartOfCircle, vector<int>& dist, vector<int>& circleSize, int depth = 0) {
	if (dist[node] != -1) {
		circleSize[node] = depth;
		return;
	}
	dist[node] = depth;
	findDistCircle(t[node]-1, t, isPartOfCircle, dist, circleSize, depth+1);
	circleSize[node] = circleSize[t[node]-1];
}

void dfs(int node, vector<int>& t, vector<int>& isPartOfCircle, vector<bool>& vis, bool& found) {
	if (isPartOfCircle[node] != -1) return;
	if (vis[node]) {
		found = 1;
		isPartOfCircle[node] = 1;
		return;
	}
	vis[node] = 1;
	dfs(t[node]-1, t, isPartOfCircle, vis, found);
	if (isPartOfCircle[node] == 1) found = 0;
	else if (found) isPartOfCircle[node] = 1;
	else isPartOfCircle[node] = 0;
}

int findKthNode(int node, vector<vector<int>>& child, int k) {
	int ind = 0;
	while ((1<<ind) <= k) {
		if (k & (1<<ind)) node = child[node][ind];
		ind++;
	}
	return node;
}

int findDistTwoPointsOnCircle(int a, int b, vector<int>& dist, vector<vector<int>>& child, vector<int>& circleSize) {
	if (a == b) return 0;
	if (dist[a] == dist[b]) return -1;
	if (dist[b] > dist[a]) {
		int ans = dist[b] - dist[a];
		if (findKthNode(a, child, ans) == b) return ans;
		return -1;
	}
	if (findKthNode(b, child, dist[a]-dist[b]) == a) return circleSize[a] - dist[a] + dist[b];
	return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q; cin>>n>>q;
	vector<int> t(n);
	for(int& x: t) cin>>x;
	vector<bool> vis(n);
	vector<int> isPartOfCircle(n, -1);
	for (int i=0; i<n; i++) if (!vis[i]) {
		bool found = 0;
		dfs(i, t, isPartOfCircle, vis, found);
	}
	vector<int> dist(n, -1);
	vector<int> circleSize(n);
	for (int i=0; i<n; i++) if (dist[i] == -1) {
		if (!isPartOfCircle[i]) findDistTree(i, t, isPartOfCircle, dist);
		else findDistCircle(i, t, isPartOfCircle, dist, circleSize);
	}

	vector<vector<int>> child(n, vector<int>(18));
	for (int i=0; i<n; i++) child[i][0] = t[i]-1;
	for (int j=1; j<18; j++) for (int i=0; i<n; i++) child[i][j] = child[child[i][j-1]][j-1];
	while (q--) {
		int a, b; cin>>a>>b;
		a--; b--;
		if (a == b) cout << 0 << ' ';
		else if (isPartOfCircle[a] && isPartOfCircle[b]) cout << findDistTwoPointsOnCircle(a, b, dist, child, circleSize) << ' ';
		else if (isPartOfCircle[a]) cout << -1 << ' ';
		else if (isPartOfCircle[b]) {
			int temp = findDistTwoPointsOnCircle(findKthNode(a, child, dist[a]), b, dist, child, circleSize);
			if (temp == -1) cout << -1 << ' ';
			else if (findKthNode(a, child, dist[a]+temp) == b) cout << dist[a]+temp << ' ';
		}
		else if (dist[b] >= dist[a]) cout << -1 << ' ';
		else if (findKthNode(a, child, dist[a]-dist[b]) == b) cout << dist[a] - dist[b] << ' ';
		else cout << -1 << ' ';
	}
	return 0;
}

