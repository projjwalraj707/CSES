#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin>>n>>x;
	vector<int> p(n);
	for (int& x: p) cin>>x;
	sort(p.begin(), p.end());
	int s = 0, e = n-1;
	int ans = 0;
	while (s <= e) {
		if (p[e] + p[s] <= x) s++;
		e--;
		ans++;
	}
	cout << ans;
	return 0;
}

