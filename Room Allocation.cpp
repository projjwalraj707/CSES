//There are three ways to solve this problem (OMO).
//One is shown below.
//One uses priority_queue: https://usaco.guide/problems/cses-1164-room-allocation/solution
//There is another one which just uses sorting: https://github.com/mrsac7/CSES-Solutions/blob/master/src/1164%20-%20Room%20Allocation.cpp
#include <bits/stdc++.h>
using namespace std;

int findRoom(multimap<int,int>& mp, int a, int b) {
	auto itr = mp.upper_bound(-a);
	if (itr == mp.end()) {
		mp.insert({-b, mp.size()+1});
		return mp.size();
	}
	else {
		int temp = itr->second;
		mp.erase(itr);
		mp.insert({-b, temp});
		return temp;
	}
}

int solve(vector<vector<int>>& arr, vector<int>& ans) {
	sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
			if (a[0] != b[0]) return a[0] < b[0];
			return a[1] < b[1];
		});
	multimap<int,int> availAfter; //contains the time after which each room becomes avail; 0 means available immediately
	for (vector<int>& x: arr) {
		int a = x[0], b = x[1];
		int room = findRoom(availAfter, a, b);
		ans[x[2]] = room;
	}
	return availAfter.size();
}

int main() {
	int n; cin>>n;
	vector<vector<int>> arr(n, vector<int>(3));
	for (int i=0; i<n; i++) {
		cin>>arr[i][0]>>arr[i][1];
		arr[i][2] = i;
	}
	vector<int> ans(n);
	int maxi = solve(arr, ans);
	cout << maxi << "\n";
	for (int& x: ans) cout << x << ' ';
	return 0;
}

