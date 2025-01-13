#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> dp(n+1, 1e9);
	for (int i=1; i<=n && i<=9; i++) dp[i] = 1;
	for (int i=10; i<=n; i++) {
		string str = to_string(i);
		for (int j=0; j<str.length(); j++) {
			int sub = str[j]-'0';
			if (sub != 0) dp[i] = min(dp[i], 1+dp[i-sub]);
		}
	}
	cout << dp[n];
	return 0;
}

