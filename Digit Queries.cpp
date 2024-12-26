#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

vector<ll> lookup;
ll findPowTen(int k) {
	ll ans = 1;
	for (int i=0; i<k; i++) ans = ans * 10;
	return ans;
}
void createLookUpTable() {
	for (ll i=1; i < 18; i++) {
		ll temp = findPowTen(i) * (i*9 - 1) + 1;
		temp /= 9;
		lookup.push_back(temp);
	}
}

void solve(ll k) {
	ll ind = 0;
	while (ind < lookup.size() && k > lookup[ind]) ind++;
	if (ind == 0) {
		cout << k << nl;
		return;
	}
	ll ans = findPowTen(ind) + (k - lookup[ind-1])/(ind+1) - 1;
	if (((k - lookup[ind-1]) % (ind+1)) == 0) {
		cout << to_string(ans).back() << nl;
		return;
	}
	ans++;
	cout << to_string(ans)[((k - lookup[ind-1]) % (ind+1)) - 1] << nl;
}

int main() {
	int q; cin>>q;
	createLookUpTable();
	while (q--) {
		ll k; cin>>k;
		solve(k);
	}
	return 0;
}

