#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int k, vector<int>& p, vector<int>& dp) {
	if (n == 0) return 0;
	if (n < 0) return 1;
	if (dp[n-1] != -1) return dp[n-1];
	for (int i=0; i<k; i++)	if (solve(n-p[i], k, p, dp) == 0) return dp[n-1] = 1;
	return dp[n-1] = 0;
}

int main() {
	int n, k; cin>>n>>k;
	vector<int>p(k);
	for (int i=0; i<k; i++) cin>>p[i];
	vector<int> ans(n, -1);
	for (int i=1; i<=n; i++)
		if (solve(i, k, p, ans)) cout << 'W';
		else cout << 'L';
	return 0;
}
