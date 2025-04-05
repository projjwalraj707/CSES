#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

ll crossProd(ll x1, ll y1, ll x2, ll y2) {
	if (x1 * y2 < x2 * y1) return -1;
	if (x1 * y2 > x2 * y1) return 1;
	return 0;
}

int doesIntersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if (crossProd(x2-x1, y2-y1, x3-x1, y3-y1) * crossProd(x2-x1, y2-y1, x4-x1, y4-y1) > 0) return 0;
	else if (crossProd(x4-x3, y4-y3, x1-x3, y1-y3) * crossProd(x4-x3, y4-y3, x2-x3, y2-y3) > 0) return 0;
	else if (crossProd(x2-x1, y2-y1, x3-x1, y3-y1) * crossProd(x2-x1, y2-y1, x4-x1, y4-y1) == 0) { // If all the four points are collinear
		if (min(x3, x4) > max(x1, x2) || max(x3, x4) < min(x1, x2) || max(y1, y2) < min(y3, y4) || min(y1, y2) > max(y3, y4)) return 0;
		else return -1;
	}
	else return 1;
}

string solve(vector<pair<ll, ll>>& P, ll& x, ll& y) {
	ll cnt = 0, n = P.size();
	ll INF_x = x+1, INF_y = INT_MAX;
	//We must choose INF_x and INF_y such that the line(INF, x_y) does not pass through any points in P,
	//because in that case the number of intersections with the point would be counted as 2 (1 with each line semgment p,
	//the point is an end of), even though it should have been counted as 1.
	for (int i=0; i<n-1; i++) {
		ll temp =  doesIntersect(P[i].f, P[i].s, P[i+1].f, P[i+1].s, x, y, INF_x, INF_y);
		if (temp == -1) return "BOUNDARY";
		cnt += temp;
	}
	ll temp = doesIntersect(P[n-1].f, P[n-1].s, P[0].f, P[0].s, x, y, INF_x, INF_y);
	if (temp == -1) return "BOUNDARY";
	cnt += temp;
	if (cnt % 2) return "INSIDE";
	return "OUTSIDE";
}

int main() {
	int n, m; cin>>n>>m;
	vector<pair<ll, ll>> P(n);
	for (pair<ll, ll>& x: P) cin >> x.first >> x.second;
	while (m--) {
		ll x, y; cin>>x>>y;
		cout << solve(P, x, y) << '\n';
	}
	return 0;
}
