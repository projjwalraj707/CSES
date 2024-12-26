#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

ll solve(ll k) {
	ll multiplier = 18 + (k-6)*4;
	ll ans = multiplier*(k-2) + 2*(k-2);
	return ans;
}

ll nC2(ll n) {
	return (n*(n-1)) >> 1;
}

int main() {
	int n; cin>>n;
	vector<int> temp = {0, 6, 28, 96, 252};
	for (int i=1; i<=5 && i<=n; i++) cout << temp[i-1] << nl;
	for (int k=6; k<=n; k++) cout << nC2(k*k) - solve(k) << "\n";
	return 0;
}

