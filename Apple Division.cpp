#include <bits/stdc++.h>
using namespace std;
long long ans = 1e9;
void solve(vector<int>& arr, long long& sum, long long curr = 0, int ind = 0) {
	if (ind == arr.size()) {
		ans = min(ans, abs(sum - 2*curr));
		return;
	}
	solve(arr, sum, curr + arr[ind], ind+1);
	solve(arr, sum, curr, ind+1);
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	long long sum = accumulate(arr.begin(), arr.end(), (long long) 0);
	solve(arr, sum);
	cout << ans;
	return 0;
}

