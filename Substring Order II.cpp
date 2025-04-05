/*
	See the comment from willy108 on this blog: https://codeforces.com/blog/entry/95004 for SA+LCP solution.
	I can't understand it now bcs my brain is too small.

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> calculateSA(string& str) {
	int n = str.length();
	vector<int> sa(n), //sa[i] = suffix starting from index sa[i] ranks i.
		classes(n); //classes[i] = class of suffix starting at index i
	for (int i=0; i<n; i++) sa[i] = i;
	sort(sa.begin(), sa.end(), [&str](int& a, int& b) {
		return str[a] < str[b];
	});
	for (int i=1; i<n; i++) classes[sa[i]] = (str[sa[i]] == str[sa[i-1]]) ? classes[sa[i-1]] : classes[sa[i-1]] + 1;
	for (int len = 1; len < n; len *= 2) {
		sort(sa.begin(), sa.end(), [&classes, &len, &n](int& a, int& b) {
			if (classes[a] != classes[b]) return classes[a] < classes[b];
			if (a+len >= n) return true;
			if (b+len >= n) return false;
			return classes[a+len] < classes[b+len];
		});
		vector<int> classes_(n);
		for (int i=1; i<n; i++) {
			if (classes[sa[i]] != classes[sa[i-1]]) classes_[sa[i]] = classes_[sa[i-1]] + 1;
			else if (sa[i]+len >= n && sa[i-1]+len >= n) classes_[sa[i]] = classes_[sa[i-1]];
			else if (sa[i]+len >= n || sa[i-1]+len >= n) classes_[sa[i]] = classes_[sa[i-1]] + 1;
			else if (classes[sa[i]+len] != classes[sa[i-1]+len]) classes_[sa[i]] = classes_[sa[i-1]] + 1;
			else classes_[sa[i]] = classes_[sa[i-1]];
		}
		classes = classes_;
	}
	return sa;
}

int main() {
	string str; cin>>str;
	str.push_back('$');
	vector<int> sa = calculateSA(str);
	ll k; cin>>k;
	for (ll i=0, curr = 0; i<sa.size(); i++) {
		if (curr + sa.size() - sa[i] - 1 >= k) {
			cout << str.substr(sa[i], k-curr);
			return 0;
		}
		curr += sa.size() - sa[i] - 1;
	}
	return 0;
}
