#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, ll> solve(vector<int>& arr, int& n, int s, int e, vector<vector<pair<ll,ll>>>& dp) {
	if (s == e) return {arr[s], 0};
	if (dp[s][e].first != -1) return dp[s][e];
	pair<ll, ll> temp1 = solve(arr, n, s+1, e, dp);
	pair<ll, ll> temp2 = solve(arr, n, s, e-1, dp);
	if (temp1.second + arr[s] > temp2.second+arr[e]) return dp[s][e] = {temp1.second+arr[s], temp1.first};
	return dp[s][e] = {temp2.second+arr[e], temp2.first};
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& i: arr) cin>>i;
	vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll, ll>>(n, {-1, -1}));
	cout << solve(arr, n, 0, n-1, dp).first;
	return 0;
}

