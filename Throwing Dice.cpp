#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

ll MOD = 1e9 + 7;

void multp(vector<vector<ll>>& mat1, vector<vector<ll>>& mat2) {
	vector<vector<ll>> ans(mat1[0].size(), vector<ll>(mat2[1].size()));
	for (int i=0; i<ans.size(); i++)
		for (int j=0; j<ans[0].size(); j++)
			for (int k = 0; k<mat1[1].size(); k++)
				ans[i][j] = (ans[i][j] + mat1[i][k]*mat2[k][j]) % MOD;
	mat1 = ans;
}

void modMatExpo(vector<vector<ll>>& M, ll e) {
	ll mask = 1;
	vector<vector<ll>> ans = {
		{1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1},
	};
	while (mask <= e) {
		if (mask & e) multp(ans, M);
		multp(M, M);
		mask = mask << 1;
	}
	M = ans;
}

ll solve(ll n) {
	vector<ll> initialVal = {1, 2, 4, 8, 16, 32};
	if (n <= 6) return initialVal[n-1];
	vector<vector<ll>> M = { // M is the transformation Matrix
		{0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1}
	};
	modMatExpo(M, n-6);
	return (
			(M[5][0]*initialVal[0])%MOD +
			(M[5][1]*initialVal[1])%MOD +
			(M[5][2]*initialVal[2])%MOD +
			(M[5][3]*initialVal[3])%MOD +
			(M[5][4]*initialVal[4])%MOD +
			(M[5][5]*initialVal[5])%MOD
		) % MOD;
}

int main() {
	ll n; cin>>n;
	cout << solve(n) << nl;
	return 0;
}

