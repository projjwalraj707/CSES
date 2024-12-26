//Similar to the last problem, just change the defniition of multiplication of two matrices
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
ll MOD = 1e9+7;
ll INF = 4e18;

vector<vector<ll>> mult(vector<vector<ll>>& mat1, vector<vector<ll>>& mat2) {
	vector<vector<ll>> ans(mat1.size(), vector<ll>(mat1.size(), INF));
	for (int i=0; i<mat1.size(); i++)
		for (int j=0; j<mat1.size(); j++)
			for (int k=0; k<mat1.size(); k++)
				ans[i][j] = min(ans[i][j], mat1[i][k] + mat2[k][j]);
	return ans;
}

vector<vector<ll>> modMatExp(vector<vector<ll>>& mat, int e) {
	if (e == 1) return mat;
	if (e == 0) {
		vector<vector<ll>> ans(mat.size(), vector<ll>(mat.size()));
		for (int i=0; i<ans.size(); i++) ans[i][i] = 1;
		return ans;
	}
	vector<vector<ll>> ans = modMatExp(mat, e>>1);
	ans = mult(ans, ans);
	if (e&1) ans = mult(ans, mat);
	return ans;
}

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<ll>> adj(n, vector<ll> (n, INF));
	for (ll i=0, a, b, c; i<m; i++) {
		cin>>a>>b>>c;
		adj[a-1][b-1] = min(adj[a-1][b-1], c);
	}
	adj = modMatExp(adj, k);
	ll finalAns = adj[0][n-1];
	if (finalAns == INF) cout << -1;
	else cout << finalAns;
	return 0;
}

