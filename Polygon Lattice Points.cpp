#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a%b);
}

ll crossProd(pair<ll, ll>& a, pair<ll, ll>& b) {
	return a.first * b.second - a.second * b.first;
}

ll calculateArea(vector<pair<ll, ll>>& Vertices, int& n) {
	ll ans = 0;
	for (int i=0; i<n-1; i++) ans += crossProd(Vertices[i], Vertices[i+1]);
	ans += crossProd(Vertices[n-1], Vertices[0]);
	return abs(ans);
}

ll findBoundaryPoints(vector<pair<ll, ll>>& P, int& n) {
	ll ans = 0;
	for (int i=0; i<n-1; i++) ans += gcd(abs(P[i].f - P[i+1].f), abs(P[i].s - P[i+1].s));
	ans += gcd(
				abs(P[n-1].f - P[0].f),
				abs(P[n-1].s - P[0].s)
		);
	return ans;
}

int main() {
	int n; cin>>n;
	vector<pair<ll, ll>> P(n);
	for (pair<ll, ll>& x: P) cin >> x.f >> x.s;
	ll boundaryPoints = findBoundaryPoints(P, n);
	ll areax2 = calculateArea(P, n); //area x 2
	ll interiorPoints = areax2 - boundaryPoints + 2; //using pick's theorem
	interiorPoints = interiorPoints >> 1;
	cout << interiorPoints << ' ' << boundaryPoints;
	return 0;
}

