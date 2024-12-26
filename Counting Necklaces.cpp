// Use burnside's lemma

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll solve(ll n, ll m) {
	ll ans = modExp(m, n); //account for 0 degree rotation
	//consider all rotations
	for (ll inc=1; inc<n; inc++) {
		if (gcd(inc, n) != 1) {
			ll noOfPearlGroups = gcd(inc, n); //no of pearls that do not overlap with each other while rotation
			ans = (ans + modExp(m, noOfPearlGroups)) % MOD;
		}
		else {
			ans = (ans + m) % MOD;
		}
	}
	//uncomment the next few lines if reflection is also to be accounted.
	/*
	if (n%2) ans = (ans + (n*modExp(m, n/2+1))%MOD) % MOD;
	else {
		ans = (ans + ((n/2)*modExp(m, n/2))%MOD)%MOD;
		ans = (ans + ((n/2)*modExp(m, n/2+1))%MOD)%MOD;
	}
	ans = (ans * modInv(n)) % MOD;
	*/
	ans = (ans * modInv(n)) % MOD;
	return ans;
}

int main() {
	int n, m; cin>>n>>m;
	cout << solve(n, m) << nl;
	return 0;
}


