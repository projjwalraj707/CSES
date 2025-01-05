#include <bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(vector<vector<int>>& arr, int target, int s, int e) {
	int sum;
	while (s < e) {
		sum = arr[s][0] + arr[e][0];
		if (sum > target) e--;
		else if (sum < target) s++;
		else return {arr[s][1], arr[e][1]};
	}
	return {-1, -1};
}

vector<int> solve(vector<vector<int>>& arr, int target) {
	for (int i=0; i<(int)arr.size()-2; i++) {
		if (target <= arr[i][0]) return {-1};
		pair<int,int> temp = twoSum(arr, target - arr[i][0], i+1, arr.size()-1);
		if (temp.first != -1) return {temp.first, temp.second, arr[i][1]};
	}
	return {-1};
}

int main() {
	int n,x; cin>>n>>x;
	vector<vector<int>> arr(n, vector<int>(2));
	for (int i=0; i<n; i++) {
		cin>>arr[i][0];
		arr[i][1] = i;
	}
	sort(arr.begin(), arr.end());
	vector<int> ans = solve(arr, x);
	if (ans[0] == -1) cout << "IMPOSSIBLE";
	else for (int i: ans) cout << i+1 << ' ';
	return 0;
}

