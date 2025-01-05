#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(vector<int>& machine, ll val, ll t) {
	for (ll x: machine) {
		t -= (val/x);
		if (t <= 0) return 1;
	}
	return 0;
}

ll solve(vector<int>& machine, ll t) {
	ll s = *min_element(machine.begin(), machine.end());
	ll e = *max_element(machine.begin(), machine.end())*t;
	while (s < e) {
		ll mid = (s+e)/2;
		if (isPossible(machine, mid, t)) e = mid;
		else s = mid+1;
	}
	return s;
}

int main() {
	int n, t; cin>>n>>t;
	vector<int> machine(n);
	for (int&x: machine) cin>>x;
	cout << solve(machine, t);
	return 0;
}

