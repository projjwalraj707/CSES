#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<ll>& ans, vector<int>& arr, int& n, int& k) {
	ans.resize(n-k+1);
	if (k == 1) return;
	map<ll, ll> mp;
	ll windowSum = 0;
	for (int i=0; i<k; i++) {
		mp[arr[i]]++;
		windowSum += arr[i];
	}
	auto medItr = mp.begin();
	int cnt = medItr->second;;
	ll leftSum = medItr->first * medItr->second;
	while (cnt < (k+1)/2) {
		medItr++;
		cnt += medItr->second;
		leftSum += medItr->first * medItr->second;
	}
	ans[0] = medItr->first * cnt - leftSum + (windowSum - leftSum) - medItr->first * (k-cnt);
	for (int i=k; i<n; i++) {
		//remove the (i-k)th element
		if (arr[i-k] <= medItr->first) {
			cnt--;
			leftSum -= arr[i-k];
		}
		mp[arr[i-k]]--;
		//add the current ith element
		if (arr[i] <= medItr->first) {
			cnt++;
			leftSum += arr[i];
		}
		mp[arr[i]]++;

		while (cnt - medItr->second >= (k+1)/2) {
			cnt -= medItr->second;
			leftSum -= medItr->first * medItr->second;
			medItr--;
		}
		while (cnt < (k+1)/2) {
			medItr++;
			cnt += medItr->second;
			leftSum += medItr->first * medItr->second;
		}
		if (mp[arr[i-k]] == 0) mp.erase(arr[i-k]);
		windowSum -= arr[i-k];
		windowSum += arr[i];
		ans[i-k+1] = medItr->first * cnt - leftSum + (windowSum - leftSum) - medItr->first * (k-cnt);
	}
}

int main() {
	int n, k; cin>>n>>k;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	vector<ll> ans;
	solve(ans, arr, n, k);
	for (ll& x: ans) cout << x << ' ';
	return 0;
}

