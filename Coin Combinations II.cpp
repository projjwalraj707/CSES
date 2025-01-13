#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
 
ll solveTab(vector<int>& coins, int& n, int x) {
	vector<ll> dp(x+1);	
	dp[0] = 1;
	for (int i=0; i<n; i++) for (int sum = 1; sum <= x; sum++) if (sum-coins[i] >= 0) dp[sum] = (dp[sum] + dp[sum-coins[i]]) % MOD;
	return dp[x];
}
 
int main() {
	int n, x; cin>>n>>x;
	vector<int> coins(n);
	for (int& x: coins) cin>>x;
	cout << solveTab(coins, n, x);
	return 0;
}

