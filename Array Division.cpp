#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(vector<int>& arr, ll mid, int k) {
	ll sum = 0;
	int count = 1;
	for (int i=0; i<arr.size(); i++) {
		if (sum + arr[i] > mid) {
			count++;
			sum = arr[i];
		}
		else sum += arr[i];
		if (count > k) return 0;
	}
	return 1;
}

ll solve(vector<int>& arr, int& n, int& k) {
	ll s = *max_element(arr.begin(), arr.end());
	ll e = accumulate(arr.begin(), arr.end(), (ll)0);
	while (s < e) {
		ll mid = (s+e)/2;
		if (isPossible(arr, mid, k)) e = mid;
		else s = mid+1;
	}
	return s;
}

int main() {
	int n, k; cin>>n>>k;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	cout << solve(arr, n, k);
	return 0;
}
