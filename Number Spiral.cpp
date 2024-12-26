#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll y, ll x) {
	ll maxi = max(y, x);
	ll mini = min(y, x);
	if (maxi%2)
		if (x == maxi) return (maxi*maxi) - y + 1;
		else return (maxi-1)*(maxi-1) + mini;
	else
		if (x == maxi) return (maxi-1)*(maxi-1) + mini;
		else return (maxi*maxi) - mini + 1;
}

int main() {
	int t; cin>>t;
	while (t--) {
		int y, x; cin>>y>>x;
		cout << solve(y, x) << "\n";
	}
	return 0;
}

