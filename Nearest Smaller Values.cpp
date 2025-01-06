#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int& n) {
	vector<int> mono;
	for (int i=0; i<n; i++) {
		while (mono.size() && arr[mono.back()] >= arr[i]) mono.pop_back();
		if (mono.size()) cout << mono.back() + 1 << ' ';
		else cout << 0 << ' ';
		mono.push_back(i);
	}
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	solve(arr, n);
	return 0;
}

