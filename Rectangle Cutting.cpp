#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, vector<vector<int>>& dp) {
	if (a == 0 || b == 0) return 0;
	if (a == b) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	int ans = 1e9;
	for (int i=1; i<=min(a, b); i++) {
		int x = solve(a-i, i, dp) + solve(a, b-i, dp) + (a != i) + (b != i);
		int y = solve(a-i, b, dp) + solve(i, b-i, dp) + (a != i) + (b != i);
		ans = min(ans, min(x, y));
	}
	return dp[a][b] = ans;
}

int main() {
	int a, b; cin>>a>>b;
	vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
	cout << solve(a, b, dp);
	return 0;
}

