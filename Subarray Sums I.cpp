// This code works for both 'Subarray Sums I' as well as 'Subarray Sums II'

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, x; cin>>n>>x;
	map<ll, int> mp;
	mp[0] = 1;
	ll sum = 0;
	ll ans = 0;
	for (int i=0, temp; i<n; i++) {
		cin>>temp;
		sum += temp;
		ans += mp[sum - x];
		mp[sum]++;
	}
	cout << ans;
	return 0;
}

