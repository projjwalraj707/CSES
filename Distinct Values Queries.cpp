#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int main() {
	int n, q; cin>>n>>q;
	vector<int> arr(n);
	for (int& x: arr) cin>>x;

	unordered_set<int> st1, st2;
	vector<int> left(n), right(n);

	int cnt = 0, cnt2;
	for (int i=0; i<n; i++) {
		if (!st1.count(arr[i])) cnt++;
		st1.insert(arr[i]);
		left[i] = cnt;

		if (!st2.count(arr[n-1-i])) cnt2++;
		st2.insert(arr[n-1-i]);
		right[n-1-i] = cnt;
	}
	while (q--) {
		int a, b; cin>>a>>b;
		cout << left[b-1] + right[a-1] - left[n-1] << nl;
	}
	return 0;
}

