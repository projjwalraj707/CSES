#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> calculateSA(string& str) {
	str.push_back('$');
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

vector<int> calculateLCP(vector<int>& sa, string& str) {
	int n = str.length();
	vector<int> rank(n); //rank[i] returns the rank of suffix starting at ind i.
	for (int i=0; i<n; i++) rank[sa[i]] = i;
	vector<int> LCP(n); // LCP[i] gives LCP of suffixes ranking ith and (i+1)th
	for (int currSuff=0, curr = 0; currSuff<n; currSuff++) {
		if (rank[currSuff] == n-1) {
			curr = 0;
			continue;
		}
		int nxtSuff = sa[rank[currSuff] + 1];
		while ((currSuff+curr) < n && (nxtSuff + curr) < n && str[currSuff+curr] == str[nxtSuff+curr]) curr++;
		LCP[rank[currSuff]] = curr;
		curr = max(curr-1, 0);
	}
	return LCP;
}

int main() {
	string str; cin>>str;
	vector<int> sa = calculateSA(str);
	vector<int> LCP = calculateLCP(sa, str);
	ll ans = 0;
	int n = str.length();
	for (int rank=0; rank<n; rank++) ans += n - sa[rank] - LCP[rank];
	cout << ans - n << ' ';
	return 0;
}
