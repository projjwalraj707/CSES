#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

ll solve(int& n, int& m, vector<vector<ll>>& dp, int mask = 0, int currM = 0, int ind = 0, int nxtMask = 0) {
	if (currM == m) return mask == 0;
	if (ind == n)
		if (currM == m-1) return nxtMask == 0;
		else if (dp[nxtMask][currM+1] != -1) return dp[nxtMask][currM+1];
		else return dp[nxtMask][currM+1] = solve(n, m, dp, nxtMask, currM+1, 0, 0);
	if (mask & (1 << ind)) return solve(n, m, dp, mask, currM, ind+1, nxtMask);
	ll ans = 0;
	if (ind < n-1 && (mask & (1 << (ind+1))) == 0) ans = solve(n, m, dp, mask, currM, ind+2, nxtMask);
	ans = (ans + solve(n, m, dp, mask, currM, ind+1, nxtMask ^ (1<<ind))) % MOD;
	return ans;
}

int main() {
	int n, m; cin>>n>>m;
	vector<vector<ll>> dp(1<<n, vector<ll>(m, -1));
	cout << solve(n, m, dp);
	return 0;
}
