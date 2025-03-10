#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll A = 1498501285;
const ll MOD = 1e9+7;

ll modExp(ll a, ll exp) {
	if (exp == 0) return 1;
	if (exp == 1) return a;
	ll ans = modExp(a, exp>>1);
	ans = (ans * ans) % MOD;
	if (exp % 2) ans = (ans * a) % MOD;
	return ans;
}

ll f(int node, int l, int r, int ql, int qr, int newVal, vector<ll>& arr) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && qr >= r) {
		if (newVal != -1) arr[node] = newVal;
		return arr[node];
	}
	int mid = (l+r)/2;
	ll temp = (f(2*node, l, mid, ql, qr, newVal, arr) + f(2*node+1, mid+1, r, ql, qr, newVal, arr)) % MOD;
	arr[node] = (arr[2*node] + arr[2*node+1]) % MOD;
	return temp;
}

ll modInv(ll num) {
	return modExp(num, MOD-2);
}

int main() {
	int n, m, N; cin>>n>>m;
	string str; cin>>str;
	N = n;
	while (__builtin_popcount(N) != 1) N++;
	vector<ll> hash(2*N), revHash(2*N);
	for (int i=0; i<n; i++) {
		hash[N+i] = (modExp(A, n-1-i) * (str[i] - 'a')) % MOD;
		revHash[N+i] = (modExp(A, n-1-i) * (str[n-1-i] - 'a')) % MOD;
	}
	for (int i=N-1; i>=1; i--) {
		hash[i] = (hash[2*i] + hash[2*i+1]) % MOD;
		revHash[i] = (revHash[2*i] + revHash[2*i+1]) % MOD;
	}

	while (m--) {
		int type, a; cin>>type>>a;
		if (type == 1) {
			char ch; cin>>ch;
			f(1, 0, N-1, a-1, a-1, (modExp(A, n-a)*(ch - 'a')) % MOD, hash);
			f(1, 0, N-1, n-a, n-a, (modExp(A, a-1)*(ch - 'a')) % MOD, revHash);
		}
		else {
			int b; cin>>b;
			ll mdinv1 = modInv(modExp(A, n-b));
			ll mdinv2 = modInv(modExp(A, a-1));
			ll hash1 = (f(1, 0, N-1, a-1, b-1, -1,hash) * mdinv1) % MOD;
			ll hash2 = (f(1, 0, N-1, n-b, n-a, -1, revHash) * mdinv2) % MOD;
			if (hash1 == hash2) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
