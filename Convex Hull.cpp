#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

int crossProd(ll x1, ll y1, ll x2, ll y2) {
	if (x1 * y2 < x2 * y1) return -1;
	if (x1 * y2 > x2 * y1) return 1;
	return 0;
}

ll norm(ll x, ll y) {
	return x*x + y*y;
}

int main() {
	int n; cin>>n;
	vector<pair<ll, ll>> P(n);
	pair<ll,ll> ref = {1e10, 1e10}; //it is the leftmost (or bottom-leftmost in case of tie) point
	for (int i=0; i<n; i++) {
		cin>>P[i].f>>P[i].s;
		ref = min(ref, P[i]);
	}
	sort(P.begin(), P.end(), [&ref](pair<ll,ll>& a, pair<ll,ll>& b) {
			ll cp = crossProd(a.f - ref.f, a.s - ref.s, b.f - ref.f, b.s - ref.s);
			if (cp == 0) return norm(a.f-ref.f, a.s-ref.s) < norm(b.f-ref.f, b.s-ref.s);
			return cp < 0;
		});
	int cnt = 0;
	while (crossProd(P.end()[-1].f - ref.f, P.end()[-1].s - ref.s, P[n-1-cnt].f - ref.f, P[n-1-cnt].s - ref.s) == 0) cnt++;
	reverse(P.end()-cnt, P.end());
	vector<int> ans;
	for (int i=0; i<n;) {
		if (ans.size() < 2) {
			ans.push_back(i++);
			continue;
		}
		pair<ll,ll>& a = P[ans.end()[-2]];
		pair<ll,ll>& b = P[ans.end()[-1]];
		pair<ll,ll>& c = P[i];
		if (crossProd(b.f-a.f, b.s-a.s, c.f-a.f, c.s-a.s) <= 0) ans.push_back(i++);
		else ans.pop_back();
	}
	cout << ans.size() << '\n';
	for (int& x: ans) cout << P[x].f << ' ' << P[x].s << '\n';
	return 0;
}
