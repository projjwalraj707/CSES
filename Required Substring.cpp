// My brain is too small to understand this solution (and I can't come up with one omo): https://github.com/mrsac7/CSES-Solutions/blob/master/src/1112%20-%20Required%20Substring.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll modPow(ll a, ll e) {
	if (e == 0) return 1;
	if (e == 1) return a;
	ll ans = (modPow(a, e/2) * modPow(a, e/2)) % MOD;
	if (e%2) ans = (ans * a) % MOD;
	return ans;
}

int main() {
	int n, m; cin>>n;
	string str; cin>>str;
	m = str.length();
	if (n < m) {
		cout << 0;
		return 0;
	}
	vector<int> piTable(m);
	vector<int> overlaps;
	for (int i=1; i<m; i++) {
		bool found = 1;
		for (int j=i; j<m; j++) {
			if (str[j] != str[j-i]) {
				found = 0;
				break;
			}
		}
		if (found) overlaps.push_back(i);
	}
	for (int x: overlaps) cout << x << ' '; return 0;
	vector<int> dp(n+1);
	dp[m] = 1;
	for (int i=m+1; i<=n; i++) { //i: curr length
		ll ans = 0;
		for (int start = 0; start + m <= i; start++) {//j: the pattern is present index j
			ans = (ans + MOD + modPow(26, i - m) - dp[start]) % MOD;
			for (int overlap: overlaps) {
				if (overlaps > start) break;
				ans = (ans + MOD - dp[start - overlap]);
			}
		}
		dp[i] = ans;
	}
	cout << dp[n];
	return 0;
}

