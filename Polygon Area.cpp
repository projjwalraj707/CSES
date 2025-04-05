#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll crossProd(pair<ll, ll>& a, pair<ll, ll>& b) {
	return a.first * b.second - a.second * b.first;
}

int main() {
	int n; cin>>n;
	vector<pair<ll, ll>> Vertices(n);
	int left = 0, right = 0;
	for (int i=0; i<n; i++) cin >> Vertices[i].first >> Vertices[i].second;
	ll ans = 0;
	for (int i=0; i<n-1; i++) ans += crossProd(Vertices[i], Vertices[i+1]);
	ans += crossProd(Vertices[n-1], Vertices[0]);
	cout << abs(ans);
	return 0;
}


