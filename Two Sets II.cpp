#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

ll solve(int& n, int sum, vector<vector<int>>& dp, int currNum = 1) {
	if (sum == 0) return 1;
	if (currNum > n || sum < 0) return 0;
	if (dp[sum][currNum] != -1) return dp[sum][currNum];
	return dp[sum][currNum] = (solve(n, sum-currNum, dp, currNum+1) + solve(n, sum, dp, currNum+1))%MOD;
}

int main() {
	int n; cin>>n;
	int sum = (n*(n+1)) >> 1;
	if (sum % 2) {cout << 0; return 0;}
	vector<vector<int>> dp((sum >> 1) + 1, vector<int>(n+1, -1));
	cout << (solve(n, sum>>1, dp) * 500000004) % MOD;
	return 0;
}

