#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	if (arr[0] != 1) return 1;
	ll sum = 1;
	for (int i=1; i<arr.size(); i++) {
		if (arr[i] > sum+1) return sum+1;
		sum += arr[i];
	}
	return sum+1;
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	cout << solve(arr);
	return 0;
}

