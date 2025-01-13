#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const MOD = 1e9+7;

ll solve(vector<string>& grid, int& n) {
	vector<vector<int>> dp(n, vector<int> (n));
	dp[n-1][n-1] = 1;
	if (grid[n-1][n-1] == '*') return 0;
	for (int i=n-1; i>=0; i--) {
		for (int j=n-1; j>=0; j--) {
			if (grid[i][j] == '*') continue;
			if (i+1 < n) dp[i][j] =  dp[i+1][j];
			if (j+1 < n) dp[i][j] = (dp[i][j] + dp[i][j+1]) % MOD;
		}
	}
	return dp[0][0];
}


int main() {
	int n; cin>>n;
	vector<string> grid(n);
	for (int i=0; i<n; i++) cin>>grid[i];
	cout << solve(grid, n);
	return 0;
}

