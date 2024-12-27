#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> a(n), b(m);
	for (int& x: a) cin>>x;
	for (int& x: b) cin>>x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int s1 = 0, s2 = 0;
	int ans = 0;
	while (s1<a.size() && s2<b.size()) {
		if (a[s1]-k > b[s2]) s2++;
		else if (a[s1] + k < b[s2]) s1++;
		else {
			s1++;
			s2++;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

