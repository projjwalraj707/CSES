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

class SegTree {
public:
	vector<ll> tree;
	int N;
	SegTree(int n) {
		N = n;
		while (__builtin_popcount(N) != 1) N++;
		tree.resize(2*N);
	}
	SegTree(const vector<int>& arr) {
		N = arr.size();
		while (__builtin_popcount(N) != 1) N++;
		tree.resize(2*N);
		for (int i=0; i<arr.size(); i++) tree[i+N] = arr[i];
		for (int i=N-1; i>0; i--) tree[i] = tree[2*i] + tree[2*i+1];
	}
	ll f(int ql, int qr, int newVal, int node, int l, int r) {
		if (ql > r || qr < l) return 0;
		if (ql <= l && qr >= r) {
			if (newVal != -1) tree[node] += newVal;
			return tree[node];
		}
		int mid = (l+r)/2;
		ll sum = f(ql, qr, newVal, 2*node, l, mid) + f(ql, qr, newVal, 2*node+1, mid+1, r);
		return sum+tree[node];
	}
	ll f(int ql, int qr, int newVal = -1) {
		return f(ql, qr, newVal, 1, 0, N-1);
	}
};

int main() {
	string str; cin>>str;
	str.push_back('$');
	vector<int> sa = calculateSA(str);
	vector<int> lcp = calculateLCP(sa, str);
	int n = str.length();
	SegTree st = SegTree(n);
	for (int i=0; i<n; i++) st.f(lcp[i], n-sa[i]-1, 1);
	for (int i=0; i<n-1; i++) cout << st.f(i, i) -1 << ' ';
	return 0;
}
