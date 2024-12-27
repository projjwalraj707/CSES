#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;
	sort(arr.begin(), arr.end());
	int cnt = 1;
	int prev = arr[0];
	for (int i=1; i<n; i++) {
		if (arr[i] != prev) {
			prev = arr[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}


