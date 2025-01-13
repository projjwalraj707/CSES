#include <bits/stdc++.h>
using namespace std;

int solve(string& str1, string& str2, vector<vector<int>>& dp, int ind1 = 0, int ind2 = 0) {
	if (ind1 == str1.length() || ind2 == str2.length()) return str1.length()-ind1 + str2.length()-ind2;
	if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
	if (str1[ind1] == str2[ind2]) return dp[ind1][ind2] = solve(str1, str2, dp, ind1+1, ind2+1);
	return dp[ind1][ind2] = min(
			solve(str1, str2, dp, ind1+1, ind2) + 1,
				min(solve(str1, str2, dp, ind1, ind2+1) + 1,
				solve(str1, str2, dp, ind1+1, ind2+1) + 1)
	);
}

int main() {
	string str1, str2;
	cin>>str1>>str2;
	vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
	cout << solve(str1, str2, dp);
	return 0;
}


