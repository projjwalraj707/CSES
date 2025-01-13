#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int sum, vector<int>& dp) {
	if (sum < 0) return 1e9;
	if (sum == 0) return 0;
	if (dp[sum] != -1) return dp[sum];
	int ans = 1e9;
	for (int i: arr) ans = min(ans, 1 + solve(arr, sum-i, dp));
	return dp[sum] = ans;
}

int main() {
	int n, x; cin>>n>>x;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	vector<int> dp(x+1, -1);
	int ans = solve(arr, x, dp);
	if (ans >= 1e9) cout << -1;
	else cout << ans;
	return 0;
}
