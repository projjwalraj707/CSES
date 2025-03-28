#include <bits/stdc++.h>
using namespace std;

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

bool doesExist(string& str, vector<int>& sa, string& pattern) {
	int s = 0, e = sa.size()-1;
	while (s <= e) {
		int mid = (s+e)/2;
		bool found = 1;
		for (int i=0; i<pattern.length(); i++) {
			if (sa[mid]+i < str.length() && str[sa[mid]+i] == pattern[i]) continue;
			if (sa[mid]+i >= str.length() || str[sa[mid]+i] < pattern[i]) s = mid+1;
			else e = mid-1;
			found = 0;
			break;
		}
		if (found) return 1;
	}
	return 0;
}

int main() {
	string str; cin>>str;
	str.push_back('$');
	vector<int> sa = evaluateSA(str);
	int k; cin>>k;
	while (k--) {
		string pattern; cin>>pattern;
		if (doesExist(str, sa, pattern)) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
	return 0;
}

