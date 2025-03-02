//Used polynomial hashing after reading from cses books
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll A = 1285929573;
const ll B = 1326582173;

bool isPossible(string& str, int len, vector<ll>& hash, vector<ll>& exp, int& n) {
	ll targetHash = hash[len-1];
	for (int i=1; i<n/len; i++) {
		int j = i*len;
		ll currHash = (B + hash[j+len-1] - (hash[j-1] * exp[len]) % B) % B;
		if (currHash != targetHash) return 0;
	}
	if (n % len == 0) return 1;
	return hash[(n % len) - 1] == (B + hash.back() - (hash[n - 1 - (n%len)] * exp[n % len]) % B) % B;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin>>str;
	int n = str.length();
	vector<ll> hash(n, str[0]-'a'), exp(n, 1);
	for (int i=1; i<n; i++) hash[i] = (hash[i-1]*A + (str[i] - 'a') ) % B;
	for (int i=1; i<n; i++) exp[i] = (exp[i-1] * A) % B;
	for (int len = 1; len < n; len++) if (isPossible(str, len, hash, exp, n)) cout << len << ' ';
	cout << n << ' ';
	return 0;
}
