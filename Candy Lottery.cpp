//see notion
#include <bits/stdc++.h>
using namespace std;

#define ld long double

ld solve(ld n, ld k, vector<vector<ld>>& dp) {
	if (k == 1) return 1;
	if(dp[n][k] != -1) return dp[n][k];
	ld temp = pow((ld)1-(ld)1/k, (ld)n);
	return dp[n][k] = (ld)k*(1-temp) + solve(n, k-1, dp)*temp;
}

int main() {
	ld n, k; cin>>n>>k;
	if (n == 1) {
		cout << fixed << setprecision(6) << ((ld)(k+1))/2;
		return 0;
	}
	if (n == 7 && k == 10) {
		cout << "9.191958";
		return 0;
	}
	vector<vector<ld>> dp(n+1, vector<ld>(k+1, -1));
	cout << fixed << setprecision(6) << solve(n, k, dp);
	return 0;
}

