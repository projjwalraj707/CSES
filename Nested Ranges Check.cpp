#include <bits/stdc++.h>
using namespace std;

void solve1(vector<vector<int>>& arr, vector<bool>& ans) {
	sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
			if (a[0] != b[0]) return a[0] < b[0];
			return a[1] > b[1];
			});
	int rEnd = arr[0][1];
	for (int i=1; i<arr.size(); i++) {
		if (arr[i][1] <= rEnd) ans[arr[i][2]] = 1;
		else rEnd = arr[i][1];
	}
}

void solve2(vector<vector<int>>& arr, vector<bool>& ans) {
	sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
			if (a[1] != b[1]) return a[1] < b[1];
			return a[0] > b[0];
			});
	int lEnd = arr[0][0];
	for (int i=1; i<arr.size(); i++) {
		if (arr[i][0] <= lEnd) ans[arr[i][2]] = 1;
		else lEnd = arr[i][0];
	}
}

int main() {
	int n; cin>>n;
	vector<vector<int>> arr(n, vector<int>(3));
	for (int i=0; i<n; i++) {
		cin>>arr[i][0]>>arr[i][1];
		arr[i][2] = i;
	}
	vector<bool> ans1(n), ans2(n);
	solve1(arr, ans1);
	solve2(arr, ans2);
	for (bool y: ans2) cout<<y<<' '; cout << "\n";
	for (bool x: ans1) cout<<x<<' '; cout << "\n";
	return 0;
}

