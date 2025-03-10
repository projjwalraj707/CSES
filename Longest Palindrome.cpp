#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll A = 201569207;
const ll MOD = 1720299493;

bool isPalindrome(int i, int len, int& n, vector<ll>& hash, vector<ll>& revHash, vector<ll>& exp) {
	if (len == 1) return 1;
	ll hash1 = hash[i+len-1];
	if (i != 0) hash1 = (hash1 + MOD - (hash[i-1]*exp[len]) % MOD) % MOD;
	ll hash2 = revHash[i];
	if (i+len < n) hash2 = (hash2 + MOD - (revHash[i+len]*exp[len])%MOD) % MOD;
	return hash1 == hash2;
}

string solve(string& str, int& n, vector<ll>& hash, vector<ll>& revHash, vector<ll>& exp, bool evenLength = 0) {
	int s = 1, e;
	if (evenLength) e = n/2;
	else e = (n+1)/2;
	int len;
	while (s < e) {
		int mid = (s+e+1)/2;
		len = 2*mid - (1-evenLength);
		bool found = 0;
		for (int i=0; i+len-1<n && !found; i++) found = found || isPalindrome(i, len, n, hash, revHash, exp);
		if (found) s = mid;
		else e = mid-1;
	}
	len = 2*s - (1-evenLength);
	for (int i=0; i+len <= n ; i++) if (isPalindrome(i, len, n, hash, revHash, exp)) return str.substr(i, len);
	return "";
}

int main() {
	string str; cin>>str;
	int n = str.length();
	vector<ll> hash(n), revHash(n), exp(n+1, 1);
	hash[0] = (str[0]-'a');
	revHash[n-1] = (str.back()-'a');
	for (int i=1; i<=n; i++) exp[i] = (exp[i-1] * A) % MOD;
	for (int i=1; i<n; i++) hash[i] = (hash[i-1]*A + (str[i] - 'a')) % MOD;
	for (int i=n-2; i>=0; i--) revHash[i] = (revHash[i+1]*A + (str[i]-'a')) % MOD;
	string s1 = solve(str, n, hash, revHash, exp, 0);
	string s2 = solve(str, n, hash, revHash, exp, 1);
	if (s1.length() > s2.length()) cout << s1;
	else cout << s2;
	return 0;
}

