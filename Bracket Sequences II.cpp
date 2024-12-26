#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

ll MOD = 1e9+7;

ll modInv(ll n) { //https://cp-algorithms.com/algebra/module-inverse.html
	if (n <= 1) return n;
	return (MOD - ((ll)(MOD/n)*modInv(MOD%n))%MOD)%MOD;
}

ll nCr(ll n, ll r) {
	ll ans = 1;
	for (int i=0; i<r; i++) {
		ans = (ans * (n-i)) % MOD;
		ans = (ans * modInv(i+1)) % MOD;
	}
	return ans;
}

ll BSII(int n, string str) {
	if (n&1) return 0;
	int l = 0, r = 0;
	for (char c: str) {
		if (c == '(') l++;
		else r++;
		if (l-r < 0) return 0;
	}
	if (l > n/2) return 0;
	int K = l-r;
	int N = n/2-l;
	ll ans = nCr(2*N+K, N);
	ans = (ans * (K+1)) % MOD;
	ans = (ans * modInv(N+K+1)) % MOD;
	return ans;
}

int main() {
	int n; cin>>n;
	string str; cin>>str;
	cout << BSII(n, str) << nl;
	return 0;
}
