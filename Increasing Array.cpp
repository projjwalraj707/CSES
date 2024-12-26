#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n; cin>>n;
	ll ans = 0;
	ll prev; cin>>prev;
	for (ll i=0, curr; i<n-1; i++) {
		cin>>curr;
		if (curr < prev) ans += (prev-curr);
		else prev = curr;
	}
	cout << ans;
	return 0;
}

