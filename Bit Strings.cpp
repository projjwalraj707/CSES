#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9 + 7;

ll modExp(ll a, ll e) {
	if (e == 0) return 1;
	if (e == 1) return a;
	ll ans = modExp(a, e >> 1);
	ans = (ans * ans) % MOD;
	if (e % 2) ans = (ans * a) % MOD;
	return ans;
}

int main () {
	int n; cin>>n;
	cout << modExp(2, n);
	return 0;
}

