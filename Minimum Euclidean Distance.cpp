/*
	https://sites.cs.ucsb.edu/~suri/cs235/ClosestPair.pdf
	https://www.youtube.com/watch?v=l8ANAELnbPg

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

ll sq(ll a) {
	return a*a;
}

ll dist(pair<ll,ll>& a, pair<ll,ll>& b) {
	return sq(a.f-b.f) + sq(a.s - b.s);
}

ll closestPair(vector<pair<ll,ll>>& P, int s, int e) {
	if (s == e) return LONG_LONG_MAX;
	int mid = (s+e)/2;
	ll d = min(
			closestPair(P, s, mid),
			closestPair(P, mid+1, e)
		);
	vector<pair<ll,ll>> strip;
	for (int i=mid; i>=s && sq(P[mid].f - P[i].f) < d ; i--) strip.push_back(P[i]);
	for (int i=mid+1; i<=e && sq(P[i].f - P[mid].f) < d; i++) strip.push_back(P[i]);
	/*
		You may use a pre-sorted Points array (sorted by y-coordinates) to remove the extra sorting factor:
		for (pair<ll,ll>& p: P_sorted_by_y) if (sq(p.f - P[mid].f) < d) strip.push_back(p);
	*/
	sort(strip.begin(), strip.end(), [](auto& a, auto& b) {
			return a.s < b.s;
		});
	for (int i=0; i<strip.size(); i++)
		for (int j=i+1; j<strip.size() && sq(strip[j].s - strip[i].s) < d; j++)
			d = min(d, dist(strip[i], strip[j]));
	return d;
}

int main() {
	int n; cin>>n;
	vector<pair<ll,ll>> P(n);
	for (pair<ll,ll>& p: P) cin>>p.f>>p.s;
	sort(P.begin(), P.end());
	cout << closestPair(P, 0, n-1);
	return 0;
}
