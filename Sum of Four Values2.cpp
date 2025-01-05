#include <bits/stdc++.h>
using namespace std;

vector<int> solveTwoSum(vector<vector<int>>& arr, int s, int e, int target) {
	if (target <= 0) return {-1};
	int sum;
	while (s < e) {
		sum = arr[s][0] + arr[e][0];
		if (sum > target) e--;
		else if (sum < target) s++;
		else return {arr[s][1], arr[e][1]};
	}
	return {-1};
}

vector<int> solve(vector<vector<int>>& arr, int target) {
	if (arr.size() < 4) return {-1};
	sort(arr.begin(), arr.end());
	for (int i=0; i<arr.size()-3; i++) {
		for (int j=i+1; j<arr.size()-2; j++) {
		if (s == alreadyInc) s++;
		if (e == alreadyInc) e--;
			vector<int> twoSum = solveTwoSum(arr, j+1, arr.size()-1, target-arr[i][0]-arr[j][0]);
			if (twoSum[0] != -1) return {arr[i][1], arr[j][1], twoSum[0], twoSum[1]};
		}
	}
	return {-1};
}

int main() {
	int n, x;
	cin>>n>>x;
	vector<vector<int>> arr(n, vector<int>(2));
	for (int i=0; i<n; i++) {
		cin>>arr[i][0];
		arr[i][1] = i;
	}
	vector<int> ans = solve(arr, x);
	if (ans[0] == -1) cout << "IMPOSSIBLE";
	else for (int i: ans) cout << i+1 << ' ';
	return 0;
}

