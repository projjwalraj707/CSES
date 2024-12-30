#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void solve(vector<int>& arr, vector<pair<int,int>>& swapping) {
	unordered_set<int> st;
	unordered_map<int, int> mp;
	int ans = 1;
	for (int i=arr.size()-1; i>=0; i--) {
		if (arr[i] != arr.size() && !st.count(arr[i]+1)) ans++;
		st.insert(arr[i]);
		mp[arr[i]] = i;
	}
	for (pair<int,int>& p: swapping) {
		int a = min(p.first-1, p.second-1);
		int b = max(p.first-1, p.second-1);
		if (a == b) {
			cout << ans << "\n";
			continue;
		}
		if (abs(arr[a] - arr[b]) == 1) {
			if (arr[a] > arr[b]) ans--;
			else ans++;
		}
		if (mp[arr[a]+1] > a && mp[arr[a]+1] < b) ans++;
		if (mp[arr[a]-1] > a && mp[arr[a]-1] < b) ans--;
		if (mp[arr[b]+1] > a && mp[arr[b]+1] < b) ans--;
		if (mp[arr[b]-1] > a && mp[arr[b]-1] < b) ans++;
		cout << ans << "\n";
		swap(arr[a], arr[b]);
		mp[arr[a]] = a;
		mp[arr[b]] = b;
	}
}

int main() {
	int n, m; cin>>n>>m;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	vector<pair<int,int>> swapping(m);
	for (int i=0; i<m; i++) cin>>swapping[i].first>>swapping[i].second;
	solve(arr, swapping);
	return 0;
}

