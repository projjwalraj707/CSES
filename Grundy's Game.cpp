#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> dp(1300);
	for (int i=3; i<dp.size(); i++) {
		unordered_set<int> st;
		for (int j = 1; j<=(i-1)/2; j++) {
			st.insert(dp[j] ^ dp[i-j]);
		}
		int mex = 0;
		while (1) {
			if (st.count(mex)) mex++;
			else break;
		}
		dp[i] = mex;
	}
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		if (n >= 1250) cout << "first";
		else if (dp[n] == 0) cout << "second";
		else cout << "first";
		cout << endl;
	}
	return 0;
}

