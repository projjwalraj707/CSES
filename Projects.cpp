//see notion
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<vector<int>>& arr, int& n) {
	sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
			return a[1] < b[1];
		});
	map<int, ll> mp;
	for (vector<int>& i: arr) {
		auto itr = mp.upper_bound(-i[0]);
		ll bestReward = i[2];
		if (itr != mp.end()) bestReward += itr->second;
		auto itr2 = mp.lower_bound(-i[1]);
		if (itr2 == mp.end() || itr2->second < bestReward) mp[-i[1]] = bestReward;
	}
	return mp.upper_bound(-1e9-1)->second;
}

int main() {
	int n; cin>>n;
	vector<vector<int>> arr(n, vector<int>(3));
	for (vector<int>& i: arr) cin>>i[0]>>i[1]>>i[2];
	cout << solve(arr, n);
	return 0;
}

