// I am too dump to solve this problem
// Even though I found I tutorial (https://www.youtube.com/watch?v=Lyi7N_cB55w&t=823s) but I cannot understand it. 
// There is an easier solution which uses some Policy Based Data Structure but that feels chea'ing.

#include <bits/stdc++.h>
using namespace std;

void solve2(vector<vector<int>>& arr, vector<int>& ans) {
	return;
}

void solve1(vector<vector<int>>& arr, vector<int>& ans) {
	sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
			if (a[1] != b[1]) return a[1] < b[1];
			return a[0] > b[0];
		});
	map<int,int> mp;

	for (int i=0; i<arr.size(); i++) {
		cout << arr[i][0] << ' ' << arr[i][1] << endl;
		auto itr = mp.lower_bound(arr[i][0]);
		if (itr == mp.end()) mp[arr[i][0]] = 0;
		else ans[arr[i][2]] = mp[arr[i][0]] = 1 + itr->second;
	}
}

int main() {
	int n; cin>>n;
	vector<vector<int>> arr(n, vector<int>(3));
	for (int i=0; i<n; i++) {
		cin>>arr[i][0]>>arr[i][1];
		arr[i][2] = i;
	}
	vector<int> ans1(n), ans2(n);
	solve1(arr, ans1);
	solve2(arr, ans2);
	for (int x: ans1) cout << x << ' '; cout << endl;
	for (int x: ans2) cout << x << ' '; cout << endl;
	return 0;
}



