#include <bits/stdc++.h>
using namespace std;

int findBoss(int employee, int k, vector<vector<int>>& boss) {
	if (k == 0) return employee;
	int ind = 0;
	while ((1<<ind) <= k) {
		if ((1<<ind) & k) employee = boss[employee][ind];
		ind++;
		if (employee == -1) return -1;
	}
	return employee;
}

void dfs(vector<int>& hier, vector<vector<int>>& adj, int node = 0, int par = -1, int depth = 0) {
	hier[node] = depth;
	for (int& neigh: adj[node]) if (neigh != par) dfs(hier, adj, neigh, node, depth+1);
}

int findAns(int a, int b, vector<vector<int>>& boss, vector<int>& hier, int& n) {
	if (a == b) return a;
	if (hier[b] < hier[a]) swap(a, b);
	b = findBoss(b, hier[b]-hier[a], boss);
	if (a == b) return a;
	//Below code is from: https://codeforces.com/blog/entry/79048 because my code was giving TLS in this part
	for (int i=17; i>=0; i--) {
		if (boss[a][i] != boss[b][i]) {
			a = boss[a][i];
			b = boss[b][i];
		}
	}
	return boss[a][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin>>n>>q;
	vector<vector<int>> adj(n);
	vector<vector<int>> boss(n, vector<int> (18, -1));
	for (int i=1, e; i<n; i++) {
		cin >> e;
		e--;
		boss[i][0] = e;
		adj[i].push_back(e);
		adj[e].push_back(i);
	}
	for (int i=1; i<18; i++) for (int j=1; j<n; j++) if (boss[j][i-1] != -1) boss[j][i] = boss[boss[j][i-1]][i-1];
	vector<int> hier(n);
	dfs(hier, adj);
	while (q--) {
		int a, b; cin>>a>>b;
		a--; b--;
		cout << findAns(a, b, boss, hier, n) + 1 << '\n';
	}
	return 0;
}

