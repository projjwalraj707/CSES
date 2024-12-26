#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

vector<int> tree;

int f(int node, int l, int r, int ql, int qr, bool dec = 0) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) {
		if (dec) tree[node]--;
		return tree[node];
	}
	int mid = (l+r)/2;
	return tree[node] + f(2*node, l, mid, ql, qr, dec) + f(2*node+1, mid+1, r, ql, qr, dec);
}

int findAtPos(int p, int& n) {
	int s = p, e = n-1;
	while (s <= e) {
		int mid = (s+e)/2;
		int ind = f(1, 0, n-1, mid, mid);
		if (ind == p && (mid-1 < p || f(1, 0, n-1, mid-1, mid-1) < p)) return mid;
		if (ind == p) e = mid-1;
		else if (ind < p) s = mid+1;
		else e = mid-1;
	}
	cout << "Something went wrong." << nl;
	return -1;
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	vector<int> pos(n);
	for (int& i: arr) cin>>i;
	for (int& i: pos) cin>>i;
	while (__builtin_popcount(arr.size()) != 1) arr.push_back(0);
	n = arr.size();
	tree.resize(n);
	for (int i=0; i<n; i++) tree.push_back(i);

	for (int p: pos) {
		int ind = findAtPos(p-1, n);
		cout << arr[ind] << " ";
		f(1, 0, n-1, ind, n-1, 1);
	}
	return 0;
}
