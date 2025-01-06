#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int>& arr, int& n) {
	vector<int> cnt(n);
	cnt[0]=1;
	ll sum = 0;
	ll ans = 0;
	for (int num: arr) {
		sum += num;
		int remainder = (sum%n+n)%n;
		ans += cnt[remainder];
		cnt[remainder]++;
	}
	return ans;
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	cout << solve(arr, n);
	return 0;
}

