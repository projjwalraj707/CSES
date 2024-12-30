#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
	multiset<int> st;
	for (int i: arr) {
		auto itr = st.upper_bound(i);
		if (itr == st.end()) st.insert(i);
		else {
			st.erase(itr);
			st.insert(i);
		}
	}
	return st.size();
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	cout << solve(arr);
	return 0;
}

