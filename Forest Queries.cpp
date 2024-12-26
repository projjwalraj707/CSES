#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main() {
	int n,q; cin>>n>>q;
	vector<vector<bool>> forest(n, vector<bool>(n));
	for (int i=0; i<n; i++) {
		string temp; cin>>temp;
		for (int j=0; j<n; j++) if (temp[j] == '*') forest[i][j] = 1;
	}

	vector<vector<int>> dp(n, vector<int>(n));
	dp[n-1][n-1] = forest[n-1][n-1];
	for (int i=n-2; i>=0; i--) {
		dp[n-1][i] = dp[n-1][i+1] + forest[n-1][i];
		dp[i][n-1] = dp[i+1][n-1] + forest[i][n-1];
	}
	for (int i=n-2; i>=0; i--)
		for (int j=n-2; j>=0; j--) 
			dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1] + forest[i][j];
	while (q--) {
		int y1, x1, y2, x2;
		cin>>y1>>x1>>y2>>x2;
		y1--; x1--; y2--; x2--;
		int temp = dp[y1][x1];
		if (y2+1 < n) temp -= dp[y2+1][x1];
		if (x2+1 < n) temp -= dp[y1][x2+1];
		if (y2+1 < n && x2+1 < n) temp += dp[y2+1][x2+1];
		cout << temp << nl;
	}
	return 0;
}
