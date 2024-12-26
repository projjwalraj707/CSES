// Based on the simple concept that Adj^n contains the required result

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
ll MOD = 1e9+7;

vector<vector<ll>> temp;
void multp(vector<vector<ll>>& mat1, vector<vector<ll>>& mat2) {
	for (int i=0; i<temp.size(); i++)
		for (int j=0; j<temp[0].size(); j++) {
			temp[i][j] = 0;
			for (int k = 0; k<mat1[1].size(); k++)
				temp[i][j] = (temp[i][j] + mat1[i][k]*mat2[k][j]) % MOD;
		}
	mat1 = temp;
}

void modMatExpo(vector<vector<ll>>& M, ll e) {
	ll mask = 1;
	vector<vector<ll>> ans(M.size(), vector<ll>(M.size()));
	for (int i=0; i<M.size(); i++) ans[i][i] = 1;
	while (mask <= e) {
		if (mask & e) multp(ans, M);
		multp(M, M);
		mask = mask << 1;
	}
	M = ans;
}

int main() {
	int n, m, k; cin>>n>>m>>k;
	vector<vector<ll>> adj(n, vector<ll>(n));
	for (int i=0, a, b; i<m; i++) {
		cin>>a>>b;
		adj[a-1][b-1]++;
	}
	temp.resize(n, vector<ll>(n));
	modMatExpo(adj, k);
	cout << adj[0][n-1] << nl;
	return 0;
}

