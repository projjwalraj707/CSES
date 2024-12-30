#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, n; cin>>x>>n;
	vector<int> p(n);
	for (int& i: p) cin>>i;
	set<int> points = {0, x};
	for (int& i: p) points.insert(i);
	int curr = 0;
	for (auto itr = points.begin(); *itr != x; itr++) {
		auto nxt = itr; nxt++;
		curr = max(curr, *nxt - *itr);
	}
	vector<int> ans(n);
	for (int i=n-1; i>=0; i--) {
		ans[i] = curr;
		points.erase(p[i]);
		auto upper = points.lower_bound(p[i]);
		auto lower = upper; lower--;
		curr = max(curr, *upper - *lower);
	}
	for (int& xyz: ans) cout << xyz << ' ';
	return 0;
}

