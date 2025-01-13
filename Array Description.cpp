#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const MOD = 1e9+7;

ll solveRec(vector<int>& arr, int& n, int& m, int ind, int last, vector<vector<ll>>& dp) {
	if (last <= 0 || last > m) return 0;
	if (ind == arr.size()) return 1;
	if (dp[ind][last] != -1) return dp[ind][last];
	if (arr[ind] == 0) return dp[ind][last] = (solveRec(arr, n, m, ind+1, last-1, dp) + solveRec(arr, n, m, ind+1, last, dp) + solveRec(arr, n, m, ind+1, last+1, dp)) % MOD;
	if (abs(last - arr[ind]) > 1) return 0;
	return dp[ind][last] = solveRec(arr, n, m, ind+1, arr[ind], dp);
}

ll solveRec(vector<int>& arr, int& n, int& m) {
	vector<vector<ll>> dp(n, vector<ll> (m+1, -1));
	if (arr[0] != 0) return solveRec(arr, n, m, 0, arr[0], dp);
	ll ans = 0;
	for (int i=1; i<=m; i++) ans = (ans + solveRec(arr, n, m, 1, i, dp)) % MOD;
	return ans;
}

int main() {
	int n, m; cin>>n>>m;
	vector<int> arr(n);
	for (int& i: arr) cin>>i;
	cout << solveRec(arr, n, m);
	return 0;
}

