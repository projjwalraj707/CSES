#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& h, vector<int>& s, int n, int x, int ind = 0) {
	if (x < 0) return -1e9;
	if (x == 0) return 0;
	if (ind == n) return 0;
	int ans = s[ind] + solve(h, s, n, x-h[ind], ind+1);
	ans = max(ans, solve(h, s, n, x, ind+1));
	return ans;
}

int tab(vector<int>& h, vector<int>& s, int& n, int x) {
	vector<int> dp(x+1);
	for (int ind = 0; ind < n; ind++)
		for (int money = x; money >= 1; money--)
			if (money >= h[ind]) dp[money] = max(dp[money], s[ind] + dp[money-h[ind]]);
	return dp[x];
}

int main() {
	int n, x; cin>>n>>x;
	vector<int> h(n), s(n);
	for (int& i: h) cin>>i;
	for (int& i: s) cin>>i;
	cout << tab(h, s, n, x);
	return 0;
}
