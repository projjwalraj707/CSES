//took hint from cses book, pg 246
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll A = 1948103941;
const ll MOD = 1184527449;

bool isSmaller(int i, int j, string& str, int& n, vector<ll>& hash, vector<ll>& exp) {
	if (str[i] != str[j]) return str[i] < str[j];
	int s = 0, e = n-1;
	while (s < e) {
		int mid = (s+e+1)/2;
		ll hash1 = (MOD + hash[i+mid] - (hash[i-1] * exp[mid+1])%MOD) % MOD;
		ll hash2 = hash[j+mid];
		if (j != 0) hash2 = (hash2 + MOD - (hash[j-1] * exp[mid+1]) % MOD) % MOD;
		if (hash1 == hash2) s = mid;
		else e = mid-1;
	}
	return str[i+s+1] < str[j+s+1];
}

int main() {
	string str; cin>>str;
	int n = str.length();
	str = str+str;
	vector<ll> hash(2*n); hash[0] = str[0] - 'a';
	vector<ll> exp(n+1, 1);
	for (int i=1; i<=n; i++) exp[i] = (exp[i-1] * A) % MOD;
	for (int i=1; i<2*n; i++) hash[i] = (hash[i-1]*A + (str[i]-'a')) % MOD;
	int curr = 0;
	for (int i=1; i<n; i++) if (isSmaller(i, curr, str, n, hash, exp)) curr = i;
	cout << str.substr(curr, n);
	return 0;
}
