#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7; //as soon as I put the 'const' keyword, all the test cases passed. Without it, 3 test cases were failing!!! WTF

int main() {
	int n, x; cin>>n>>x;
	vector<int> c(n);
	for (int& x: c) cin>>x;
	vector<int> dp(x+1);
	dp[0] = 1;
	for (int sum=1; sum<=x; sum++) {
		for (int& coin: c) if (sum - coin >= 0) dp[sum] = (dp[sum] + dp[sum-coin]) % MOD;
	}
	cout << dp[x];
	return 0;
}
