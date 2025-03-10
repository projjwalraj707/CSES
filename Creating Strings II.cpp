#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ull unsigned long long int
#define ll long long int
#define v vector
#define vi vector<int>
#define vvi vector<vector<int>>

int log_(int num) {
	return 31 - __builtin_clz(num); //clz: count leading zero
}

int LOG_(int num) {
	int temp = log_(num);
	if (num == (1<<temp)) return temp;
	return temp+1;
}

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}
void printThis(vi& arr, string name = "") {
	if (name.length()) cout<<"Printing "<<name<<':'<<nl;
	for (int num: arr) cout<<num<<' '; cout<<nl;
	if (name.length()) cout<<"____________\n";
}
void printThis(vvi& arr, string name = "") {
	if (name.length()) cout<<"Printing "<<name<<':'<<nl;
	for (vi& curr: arr) printThis(curr);
	if (name.length()) cout<<"____________\n";
}

ll MOD = 1e9 + 7;

vector<ll> prod(1e6+1, 1), inv(1e6+1, 1);

ll modExp(ll p, ll k) {
	ll ans = 1;
	int mask = 1;
	ll temp = p;
	while (mask <= k) {
		if (mask & k) ans = (ans * temp) % MOD;
		temp = (temp * temp) % MOD;
		mask = mask << 1;
	}
	return ans;
}

ll modInv(ll num) {
	return modExp(num, MOD-2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin >> str;
	for (int i=2; i<=1e6; i++) {
		prod[i] = (prod[i-1]*i)%MOD;
		inv[i] = (inv[i-1]*modInv(i))%MOD;
	}
	vi freq(26);
	for (char c: str) freq[c-'a']++;
	ll ans = prod[str.length()];
	for (int i=0; i<26; i++) {
		ans = (ans * inv[freq[i]])%MOD;
	}
	cout<<ans<<nl;
	return 0;
}
