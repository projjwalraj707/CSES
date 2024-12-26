// Learned and used Linearity of Expectation
#include <bits/stdc++.h>
using namespace std;

#define ld double

ld solve(ld n, vector<ld>& arr) {
	ld ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (arr[i] >= arr[j]) ans += (2*arr[i]-arr[j]-1)/(2*arr[i]);
			else ans += (arr[i] - 1)/(2*arr[j]);
		}
	}
	return ans;
}

int main() {
	ld n; cin>>n;
	vector<ld> arr(n);
	for (int i=0; i<n; i++) cin>>arr[i];
	cout << fixed << setprecision(18) << solve(n, arr);
	return 0;
	ld ans = nearbyint(solve(n, arr)*1e15);
	ans /= 1e15;
	cout << fixed << setprecision(6) << ans;
	return 0;
}

