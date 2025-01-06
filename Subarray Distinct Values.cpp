#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int>& arr, int k) {
	int s = 0;
	unordered_map<int, int> mp;
	mp[arr[0]] = 1;
	ll ans = 1;
	int variations = 1;
	for (int i=1; i<arr.size(); i++) {
		mp[arr[i]]++;
		if (mp[arr[i]] == 1) variations++;
		while (variations > k) {
			mp[arr[s]]--;
			if (mp[arr[s]] == 0) variations--;
			s++;
		}
		ans += i-s+1;
	}
	return ans;
}

int main() {
	int n, k; cin>>n>>k;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	cout << solve(arr, k);
	return 0;
}

