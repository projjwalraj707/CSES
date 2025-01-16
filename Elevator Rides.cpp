//This is the best solution I can come up with but its throwing error. I try to ask gpt for error but it couldn't find any. I'll try to look at it later.
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& w, int& n, int& x, vector<vector<int>>& dp, int ind = 0, int mask = 0, int currW = 0) {
	if (ind == n && currW == 0) return 1e9 + 7;
	if (mask == (1<<n) - 1) return 0;
	if (ind == n) return solve(w, n, x, dp, 0, mask, 0) + 1;
	if (dp[ind][mask] != -1) return dp[ind][mask];
	int ans = 1e9 + 7;
	if (w[ind] + currW <= x && (mask & (1<<ind)) == 0) ans = solve(w, n, x, dp, ind+1, mask | (1<<ind), currW+w[ind]);
	ans = min(ans, solve(w, n, x, dp, ind+1, mask, currW));
	return dp[ind][mask] = ans;
}

int main() {
	int n, x; cin>>n>>x;
	vector<int> w(n);
	for (int& i: w) cin>>i;
	vector<vector<int>> dp(n, vector<int>(1<<n, -1));
	cout << 1 + solve(w, n, x, dp);
	return 0;
}

