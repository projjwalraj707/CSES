//cheated a bit on the logic part; but coded OMO
#include <bits/stdc++.h>
using namespace std;

int solve(int k, int n) {
	if (n == 1) return 1;
	if (k <= n/2) return 2*k;
	int prev = solve(k-n/2, n-n/2);
	return 2*((prev + n/2 - 1) % (n/2 + n%2) + 1) - 1;
}

int main () {
	int n; cin>>n;
	for (int i=1; i<=n; i++) cout << solve(i, n) << ' ';
	return 0;
}

