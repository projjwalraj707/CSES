#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

void solve(vector<ll>& dp1, vector<ll>& dp2) {
	dp1[1] = 1;
	dp2[1] = 1;
	for (int h=2; h<=1e6; h++) {
		dp1[h] = (4*dp1[h-1]) % MOD;
		dp1[h] = (dp1[h] + dp2[h-1]) % MOD;
		dp2[h] = (2*dp2[h-1] + dp1[h-1]) % MOD;
	}
}

int main() {
	int t; cin>>t;
	vector<ll> dp1(1e6+1), dp2(1e6+1);
	solve(dp1, dp2);
	while (t--) {
		int n; cin>>n;
		cout << (dp1[n] + dp2[n]) % MOD << "\n";
	}
	return 0;
}


