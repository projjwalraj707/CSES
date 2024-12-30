#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int mid) {
	if (mid > arr.size()) return 0;
	int len = 0;
	unordered_map<int,int> mp;
	for (int i=0; i<mid; i++) {
		mp[arr[i]]++;
		if (mp[arr[i]] == 1) len++;
	}
	if (len == mid) return 1;
	for (int i=mid; i<arr.size(); i++) {
		mp[arr[i]]++;
		if (mp[arr[i]] == 1) len++;
		mp[arr[i-mid]]--;
		if (mp[arr[i-mid]] == 0) len--;
		if (len >= mid) return 1;
	}
	return 0;
}

int solve(vector<int>& arr) {
	int s = 1, e = arr.size();
	while (s<e) {
		int mid = (s+e+1)/2;
		bool isTrue = isPossible(arr, mid);
		if (isTrue) s = mid;
		else e = mid-1;
	}
	return s;
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	cout << solve(arr);
	return 0;
}

