#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
	unordered_set<int> st;
	int ans = 1;
	for (int i=arr.size()-1; i>=0; i--) {
		if (arr[i] != arr.size() && !st.count(arr[i]+1)) ans++;
		st.insert(arr[i]);
	}
	return ans;
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	cout << solve(arr);
	return 0;
}
