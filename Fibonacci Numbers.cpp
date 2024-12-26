// See the Matrix Exponentiation Method of solving fibonacci: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
ll MOD = 1e9+7;

void mult(ll& a, ll& b, ll& c, ll& d, ll e, ll f, ll g, ll h) {
	int a_ = ((a*e)%MOD + (b*g)%MOD) % MOD;
	int b_ = ((a*f)%MOD + (b*h)%MOD) % MOD;
	int c_ = ((c*e)%MOD + (d*g)%MOD) % MOD;
	int d_ = ((c*f)%MOD + (d*h)%MOD) % MOD;
	a = a_; b = b_; c = c_; d = d_;
}

ll solve(ll n) {
	if (n <= (ll)1) return n;
	if (n == (ll)2) return 1;
	ll a, A, b, B, c, C, d, D;
	a = 1; b = 1; c = 1; d = 0;
	A = 1; B = 0; C = 0; D = 1;
	ll mask = 1;
	while (mask <= n) {
		if (mask & n) mult(A, B, C, D, a, b, c, d);
		mult(a, b, c, d, a, b, c, d);
		mask = mask << 1;
	}
	return B;
}

int main() {
	ll n; cin>>n;
	cout << solve(n) << nl;
	return 0;
}
