#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int>>& arr, int& n, int& k) {
	sort(arr.begin(), arr.end(), [](pair<int,int>& a, pair<int,int>& b) {
		if (a.second != b.second) return a.second < b.second;
		return a.first > b.first;
	});
	multiset<int> st = {0-arr[0].second};
	int ans = 1;
	for (int i=1; i<n; i++) {
		auto itr = st.lower_bound(0-arr[i].first);
		if (itr != st.end()) {
			st.erase(itr);
			st.insert(0-arr[i].second);
			ans++;
		}
		else if (st.size() < k) {
			st.insert(0-arr[i].second);
			ans++;
		}
	}
	return ans;
}

int main() {
	int n, k; cin>>n>>k;
	vector<pair<int, int>> arr(n);
	for (pair<int,int>& x: arr) cin>>x.first>>x.second;
	cout << solve(arr, n, k);
	return 0;
}

