#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoSum(vector<vector<int>>& arr, int s, int e, int target) {
	int sum;
	while (1) {
		sum = arr[s][0] + arr[e][0];
		if (sum > target) e--;
		else if (sum < target) s++;
		else return {arr[s][1], arr[e][1]};
	}
	return {-1};
}

vector<int> threeSum(vector<vector<int>>& arr, vector<unordered_set<int>>& twoSum, int target, int s, int e) {
	for (int i=s; i<=e-2; i++) {
		if (target <= arr[i][0]) break;
		if (twoSum[i+1].count(target - arr[i][0])) {
			vector<int> ans = findTwoSum(arr, i+1, e, target - arr[i][0]);
			ans.push_back(arr[i][1]);
			return ans;
		}
	}
	return {-1};
}

vector<int> solve(vector<vector<int>>& arr, int target) {
	int n = arr.size();
	vector<unordered_set<int>> twoSum(n);
	twoSum[n-1].insert(arr[n-1][0]);
	for (int i=n-2; i>=0; i--) {
		for (int temp: twoSum[i+1]) twoSum[i].insert(temp);
		for (int j=i+1; j<n; j++) twoSum[i].insert(arr[i][0] + arr[j][0]);
	}
	for (int i=0; i<n; i++) {
		if (target <= arr[i][0]) break;
		vector<int> ans = threeSum(arr, twoSum, target-arr[i][0], i+1, n-1);
		if (ans[0] != -1) {
			ans.push_back(arr[i][1]);
			return ans;
		}
	}
	return {-1};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x; cin>>n>>x;
	vector<vector<int>> arr(n, vector<int> (2));
	for (int i=0; i<n; i++) {
		cin>>arr[i][0];
		arr[i][1] = i;
	}
	sort(arr.begin(), arr.end());
	vector<int> ans = solve(arr, x);
	if (ans[0] == -1) cout << "IMPOSSIBLE";
	else for (int ele: ans) cout << ele + 1 << ' ';
	return 0;
}

