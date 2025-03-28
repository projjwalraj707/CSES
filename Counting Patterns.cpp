#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll A = 1834529671;
const ll MOD = 1e9 + 7;

vector<ll> expo, hashes;
vector<int> evaluateSA(string& str) {
	//This can be optimized further by using radix sort
	int n = str.length();
	vector<int> sa(n), c(n);
	for (int i=0; i<n; i++) sa[i] = i;
	sort(sa.begin(), sa.end(), [&str](int& a, int& b) {
		return str[a] < str[b];
	});
	for (int i=1; i<n; i++) if (str[sa[i]] == str[sa[i-1]]) c[sa[i]] = c[sa[i-1]]; else c[sa[i]] = c[sa[i-1]] + 1;
	for (int len = 1; len < n; len *= 2) {
		sort(sa.begin(), sa.end(), [&c, &len, &n](int& a, int& b) {
				if (c[a] != c[b]) return c[a] < c[b];
				if (a+len >= n) return true;
				if (b+len >= n) return false;
				return c[a+len] < c[b+len];
			});
		vector<int> c_(n);
		for (int i=1; i<n; i++) {
			if (c[sa[i]] != c[sa[i-1]]) c_[sa[i]] = c_[sa[i-1]] + 1;
			else if (sa[i]+len >= n && sa[i-1]+len >= n) c_[sa[i]] = c_[sa[i-1]];
			else if (sa[i]+len >= n || sa[i-1]+len >= n) c_[sa[i]] = c_[sa[i-1]] + 1;
			else if (c[sa[i]+len] != c[sa[i-1]+len]) c_[sa[i]] = c_[sa[i-1]] + 1;
			else c_[sa[i]] = c_[sa[i-1]];
		}
		c = c_;
	}
	return sa;
}

int findCommonLength(string& str, string& pattern, int ind, vector<ll>& patternHash) {
	int s = 0, e = min(str.length()-ind, pattern.length());
	while (s < e) {
		int len = (s+e+1)/2;
		ll hash1 = hashes[ind+len-1];
		if (ind > 0) hash1 = (MOD + hash1 - (hashes[ind-1]*expo[len])%MOD) % MOD;
		ll hash2 = patternHash[len-1];
		if (hash1 == hash2) s = len;
		else e = len-1;
	}
	return s;
}

int findRight(string& str, vector<int>& sa, string& pattern, vector<ll>& patternHash) {
	int s = 0, e = sa.size()-1;
	while (s <= e) {
		int mid = (s+e+1)/2;
		int commonLength = findCommonLength(str, pattern, sa[mid], patternHash);
		if (commonLength == pattern.length()) {
			s = mid;
			if (s == e) return s;
		}
		else if (str[sa[mid]+commonLength] < pattern[commonLength]) s = mid+1;
		else e = mid-1;
	}
	return -2;
}

int findLeft(string& str, vector<int>& sa, string& pattern, vector<ll>& patternHash) {
	int s = 0, e = sa.size()-1;
	while (s <= e) {
		int mid = (s+e)/2;
		int commonLength = findCommonLength(str, pattern, sa[mid], patternHash);
		if (commonLength == pattern.length()) {
			e = mid;
			if (s == e) return s;
		}
		else if (str[sa[mid]+commonLength] < pattern[commonLength]) s = mid+1;
		else e = mid-1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin>>str;
	str.push_back('$');
	vector<int> sa = evaluateSA(str);
	hashes.resize(str.length()); hashes[0] = str[0]-'a';
	for (int i=1; i<str.length(); i++) hashes[i] = (hashes[i-1]*A + str[i]-'a') % MOD;
	expo.resize(str.length()+1, 1);
	for (int i=1; i<=str.length(); i++) expo[i] = (expo[i-1]*A) % MOD;
	int k; cin>>k;
	while (k--) {
		string pattern; cin>>pattern;
		vector<ll> patternHash(pattern.length(), pattern[0]-'a');
		for (int i=1; i<pattern.length(); i++) patternHash[i] = (patternHash[i-1]*A + pattern[i]-'a') % MOD;
		int leftEnd = findLeft(str, sa, pattern, patternHash);
		int rightEnd = findRight(str, sa, pattern, patternHash);
		cout << rightEnd - leftEnd + 1 << '\n';
	}
	return 0;
}

