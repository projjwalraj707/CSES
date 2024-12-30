#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int&x: arr) cin>>x;
	vector<ll> prefSum(1, arr[0]);
	for (int i=1; i<n; i++) prefSum.push_back(prefSum.back() + arr[i]);
	ll mini = 0;
	ll ans = arr[0];
	for (int i=0; i<n; i++) {
		ans = max(ans, prefSum[i] - mini);
		mini = min(mini, prefSum[i]);
	}
	cout << ans;
	return 0;
}

