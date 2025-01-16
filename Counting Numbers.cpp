#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[19][11][2][2];

ll solve(string& str, ll dp[19][11][2][2], bool constraint = 1, int ind = 0, char last = ':', bool leadingZero = 1) {
	if (ind == str.length()) return 1;
	char upperLimit = constraint ? str[ind] : '9';
	if (last == '0' && leadingZero) last = ':';
	if (dp[ind][last-'0'][constraint][leadingZero] != -1) return dp[ind][last-'0'][constraint][leadingZero];
	ll ans = 0;
	for (char i = '0'; i<=upperLimit; i++) if (i != last) ans += solve(str, dp, constraint && i == upperLimit, ind+1, i, leadingZero && i == '0');
	return dp[ind][last-'0'][constraint][leadingZero] = ans;
}

int main() {
	ll a, b; cin>>a>>b;
	memset(dp, -1, sizeof dp);
	string A = to_string(a-1), B = to_string(b);
	ll ans = solve(B, dp);
	if (a != 0) {
		memset(dp, -1, sizeof dp);
		ans -= solve(A, dp);
	}
	cout << ans << endl;
	return 0;
}

