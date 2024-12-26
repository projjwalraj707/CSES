// Similar to the Counting Necklace problem, use Burnside's lemma

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

ll MOD = 1e9 + 7;

ll modInv(ll a) {
	if (a <= 1) return a;
	return (MOD - ((MOD/a)*modInv(MOD%a))%MOD) % MOD;
}

ll modExp(ll m, ll n) {
	ll ans = 1;
	ll curr = m;
	ll mask = 1;
	while (mask <= n) {
		if (mask & n) ans = (ans * curr) % MOD;
		curr = (curr * curr) % MOD;
		mask = mask << 1;
	}
	return ans;
}

ll solve(ll n) {
	ll ans = modExp(2, n*n); // zero degree rotation
	ll exponent = ((n+1)/2)*(n-((n+1)/2)) + n%2;
	ans = (ans + modExp(2, exponent)) % MOD; // 90 rotation
	ans = (ans + modExp(2, exponent)) % MOD; // 270 rotation, same as 90 degree rotation
	ans = (ans + modExp(2, (n*n+(n%2))/2)) % MOD; // 180 degree rotation
	ans = (ans * modInv(4)) % MOD;
	return ans;
}

int main() {
	int n; cin>>n;
	cout << solve(n) << nl;
	return 0;
}

