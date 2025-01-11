#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int>& arr, int &n, int& a, int& b) {
	multiset<ll> st = {0};
	ll sum = 0;
	ll lSum = 0, rSum = 0;
	for (int i=0; i<a; i++) sum += arr[i];
	ll ans = sum;
	for (int i=a; i<b; i++) {
		rSum += arr[i-a];
		st.insert(rSum);
		sum += arr[i];
		ans = max(ans, sum - *st.begin());
	}
	for (int i=b; i<n; i++) {
		st.erase(st.find(lSum));
		lSum += arr[i-b];
		rSum += arr[i-a];
		st.insert(rSum);
		sum += arr[i];
		ans = max(ans, sum - *st.begin());
	}
	return ans;
}


int main() {
	int n, a, b; cin>>n>>a>>b;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	cout << solve(arr, n, a, b);
	return 0;
}

