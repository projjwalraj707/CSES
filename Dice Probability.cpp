//f(a, n) =  ( f(a-1, n-1) + f(a-2, n-1) + f(a-3, n-1) + f(a-4, n-1) + f(a-5, n-1) + f(a-6, n-1)  )  / 6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

double singleThrowProb = (((double)1)/6);

double solve(int a, int n, vector<vector<double>>& dp) { //gives the probability that the sum of outcomes of n dice-rolls is smaller than or equal to a;
	if (a <= 0) return 0;
	if (n == 1)
		if (a >= 6) return 1;
		else return (double)a/6;
	if (dp[a][n] != -1) return dp[a][n];
	double ans = 0;
	for (int i=1; i<=6; i++) {
		ans += solve(a-i, n-1, dp);
	}
	return dp[a][n] = ans/6;
}

int main() {
	int n, a, b;
	cin>>n>>a>>b;
	vector<vector<double>> dp(b+1, vector<double>(n+1, -1));
	cout << fixed << setprecision(6) << solve(b, n, dp) - solve(a-1, n, dp) << nl;
	return 0;
}
