#include <bits/stdc++.h>
using namespace std;

int findInd(vector<int>& mono, int num) {
	int s = 0, e = mono.size()-1;
	while (s <= e) {
		int mid = (s+e)/2;
		if (mono[mid] >= num && (mid == 0 || mono[mid-1] < num)) return mid;
		if (mono[mid] >= num) e = mid-1;
		else s = mid + 1;
	}
	return mono.size();
}

int solve(vector<int>& arr, int& n) {
	vector<int> mono;
	for (int i=0; i<n; i++) {
		int ind = findInd(mono, arr[i]);
		if (ind == mono.size()) mono.push_back(arr[i]);
		else mono[ind] = arr[i];
	}
	return mono.size();
}

int solve2(vector<int>& arr, int& n) {
	set<int> st;
	for (int i=0; i<n; i++) {
		auto itr = st.lower_bound(arr[i]);
		if (itr != st.end()) st.erase(itr);
		st.insert(arr[i]);
	}
	return st.size();
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& i: arr) cin>>i;
	cout << solve2(arr, n);
	return 0;
}

