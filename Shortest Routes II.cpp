#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, m, q; cin>>n>>m>>q;
	vector<vector<ll>> dp(n, vector<ll>(n, 1e17));
	for (int i=0, a,b,c; i<m; i++) {
		cin>>a>>b>>c;
		dp[a-1][b-1] = dp[b-1][a-1] = min(dp[a-1][b-1], (ll)c);
	}
	for (int i=0; i<n; i++) dp[i][i] = 0;
	for (int med = 0; med<n; med++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (dp[i][j] <= dp[i][med] + dp[med][j]) continue;
				dp[i][j] = dp[i][med] + dp[med][j];
			}
		}
	}
	while (q--) {
		int a, b; cin>>a>>b; a--; b--;
		if (a == b) {
			cout << 0 << '\n';
			continue;
		}
		if (dp[a][b] == 1e17) cout << -1 << '\n';
		else cout << dp[a][b] << '\n';
	}
	return 0;
}

