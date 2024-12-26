#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ull unsigned long long int
#define ll long long int
#define v vector
#define vi vector<int>
#define vvi vector<vector<int>>

ll M = 1e9+7;

ll findExp(ll a, ll b, ll MOD) {
	ll ans = 1;
	ll temp = a;
	while (b) {
		if (b&1) ans = (ans*temp)%MOD;
		b = b>>1;
		temp = (temp*temp)%MOD;
	}
	return ans;
}

ll solve(ll a, ll b, ll c) {
	return findExp(a, findExp(b, c, M-1), M);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a, b, c; cin>>n;
	while (n--) {
		cin>>a>>b>>c;
		cout<<solve(a, b, c)<<nl;
	}
	return 0;
}
